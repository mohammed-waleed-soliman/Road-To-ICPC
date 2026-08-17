// LCA with Binary Lifting
// Supports:
//   - Lowest Common Ancestor
//   - K-th ancestor
//   - Distance between two nodes
//
// Preprocessing: O(N log N)
// Query: O(log N)

struct LCA
{
    int n, LOG;
    vector<int> depth;
    vector<vector<int>> up;

    void build(const vector<vector<int>> &adj, int root = 1)
    {
        n = adj.size();
        LOG = 1;

        while ((1 << LOG) <= n)
            LOG++;

        depth.assign(n, 0);
        up.assign(n, vector<int>(LOG));

        dfs(root, root, adj);
    }

    // Builds parent and binary lifting table
    void dfs(int u, int parent, const vector<vector<int>> &adj)
    {
        up[u][0] = parent;

        for (int j = 1; j < LOG; j++)
            up[u][j] = up[up[u][j - 1]][j - 1];

        for (int v : adj[u])
        {
            if (v == parent)
                continue;

            depth[v] = depth[u] + 1;
            dfs(v, u, adj);
        }
    }

    // Returns the k-th ancestor of u
    int kthAncestor(int u, int k)
    {
        for (int j = 0; j < LOG; j++)
        {
            if (k & (1 << j))
                u = up[u][j];
        }

        return u;
    }

    // Returns the Lowest Common Ancestor of a and b
    int lca(int a, int b)
    {
        // Make a the deeper node
        if (depth[a] < depth[b])
            swap(a, b);

        // Bring a to the same depth as b
        a = kthAncestor(a, depth[a] - depth[b]);

        if (a == b)
            return a;

        // Move both nodes up while their ancestors differ
        for (int j = LOG - 1; j >= 0; j--)
        {
            if (up[a][j] != up[b][j])
            {
                a = up[a][j];
                b = up[b][j];
            }
        }

        return up[a][0];
    }

    // Returns the number of edges between a and b
    int distance(int a, int b)
    {
        int lc = lca(a, b);

        return depth[a] + depth[b] - 2 * depth[lc];
    }
};



// LCA with Binary Lifting + maximum edge on a path
//
// Supports:
//   - Lowest Common Ancestor
//   - K-th ancestor
//   - Maximum edge from a node to its k-th ancestor
//   - Maximum edge on the path between two nodes
//
// Preprocessing: O(N log N)
// Query: O(log N)

struct LCA
{
    int n, LOG;
    vector<int> depth;

    // up[u][j] = 2^j-th ancestor of u
    vector<vector<int>> up;

    // mx[u][j] = maximum edge on the path
    // from u to its 2^j-th ancestor
    vector<vector<int>> mx;

    void build(const vector<vector<pair<int,int>>> &adj, int root = 1)
    {
        n = adj.size();
        LOG = 1;

        while ((1 << LOG) <= n)
            LOG++;

        depth.assign(n, 0);
        up.assign(n, vector<int>(LOG, root));
        mx.assign(n, vector<int>(LOG, 0));

        dfs(root, root, 0, adj);
    }

    // Builds the binary lifting and maximum-edge tables
    void dfs(
        int u,
        int parent,
        int weight,
        const vector<vector<pair<int,int>>> &adj
    )
    {
        up[u][0] = parent;
        mx[u][0] = weight;

        for (int j = 1; j < LOG; j++)
        {
            // 2^j-th ancestor
            up[u][j] = up[up[u][j - 1]][j - 1];

            // Maximum edge in the 2^j-length path
            mx[u][j] = max(
                mx[u][j - 1],
                mx[up[u][j - 1]][j - 1]
            );
        }

        for (auto [v, w] : adj[u])
        {
            if (v == parent)
                continue;

            depth[v] = depth[u] + 1;

            dfs(v, u, w, adj);
        }
    }

    // Returns the k-th ancestor of u
    int kthAncestor(int u, int k)
    {
        for (int j = 0; j < LOG; j++)
        {
            if (k & (1 << j))
                u = up[u][j];
        }

        return u;
    }

    // Returns the maximum edge on the path
    // from u to its k-th ancestor
    int maxToAncestor(int u, int k)
    {
        int ans = 0;

        for (int j = 0; j < LOG; j++)
        {
            if (k & (1 << j))
            {
                ans = max(ans, mx[u][j]);
                u = up[u][j];
            }
        }

        return ans;
    }

    // Returns the Lowest Common Ancestor of a and b
    int lca(int a, int b)
    {
        if (depth[a] < depth[b])
            swap(a, b);

        // Bring a to the same depth as b
        a = kthAncestor(a, depth[a] - depth[b]);

        if (a == b)
            return a;

        // Move both nodes upward until their parents are equal
        for (int j = LOG - 1; j >= 0; j--)
        {
            if (up[a][j] != up[b][j])
            {
                a = up[a][j];
                b = up[b][j];
            }
        }

        return up[a][0];
    }

    // Returns the maximum edge weight on the path a -> b
    int maxPath(int a, int b)
    {
        int lc = lca(a, b);

        int left = maxToAncestor(
            a,
            depth[a] - depth[lc]
        );

        int right = maxToAncestor(
            b,
            depth[b] - depth[lc]
        );

        return max(left, right);
    }
};
