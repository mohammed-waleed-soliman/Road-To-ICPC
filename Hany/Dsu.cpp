struct DSU
{
    vector<int> p, sz;

    DSU(int n)
    {
        p.resize(n);
        sz.assign(n, 1);

        iota(p.begin(), p.end(), 0);
    }

    int find(int x)
    {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);

        if (a == b)
            return false;

        if (sz[a] < sz[b])
            swap(a, b);

        p[b] = a;
        sz[a] += sz[b];

        return true;
    }

    bool same(int a, int b)
    {
        return find(a) == find(b);
    }
};





// DSU / Disjoint Set Union
// Maintains a collection of disjoint sets.
// Supports:
//   - Merge two sets
//   - Check if two nodes are in the same set
//   - Get component size
//   - Get minimum / maximum node in a component

struct DSU
{
    vector<int> p;          // Parent of each node
    vector<int> sz;         // Size of each component
    vector<int> mn, mx;     // Minimum / maximum node in each component

    DSU(int n)
    {
        init(n);
    }

    // Initialize n independent components
    void init(int n)
    {
        p.resize(n + 1);
        sz.assign(n + 1, 1);
        mn.resize(n + 1);
        mx.resize(n + 1);

        for (int i = 1; i <= n; i++)
        {
            p[i] = i;
            mn[i] = mx[i] = i;
        }
    }

    // Returns the representative (root) of x's component
    // Uses path compression for faster future queries
    int find(int x)
    {
        if (p[x] == x)
            return x;

        return p[x] = find(p[x]);
    }

    // Merges the components containing a and b
    // Returns false if they were already connected
    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);

        if (a == b)
            return false;

        // Attach the smaller component to the larger one
        if (sz[a] < sz[b])
            swap(a, b);

        p[b] = a;

        // Update information of the new component
        sz[a] += sz[b];
        mn[a] = min(mn[a], mn[b]);
        mx[a] = max(mx[a], mx[b]);

        return true;
    }

    // Returns the size of x's component
    int size(int x)
    {
        return sz[find(x)];
    }

    // Returns the minimum node in x's component
    int getMin(int x)
    {
        return mn[find(x)];
    }

    // Returns the maximum node in x's component
    int getMax(int x)
    {
        return mx[find(x)];
    }

    // Checks whether a and b belong to the same component
    bool same(int a, int b)
    {
        return find(a) == find(b);
    }
};



// DSU with Parity
//
// Used when every connection has a relationship:
//   0 -> same color / same group
//   1 -> different color / different group
//
// Useful for:
//   - Bipartite graph problems
//   - "Same / different" constraints
//   - Detecting contradictions

struct DSU
{
    vector<int> p;          // Parent of each node
    vector<int> sz;         // Size of each component
    vector<int> parity;     // Relationship between node and its parent
                            // 0 = same, 1 = different

    DSU(int n)
    {
        p.resize(n);
        sz.assign(n, 1);
        parity.assign(n, 0);

        for (int i = 0; i < n; i++)
            p[i] = i;
    }

    // Returns:
    //   first  -> component representative
    //   second -> relationship between x and the representative
    pair<int, int> find(int x)
    {
        if (p[x] == x)
            return {x, 0};

        auto [root, par] = find(p[x]);

        // Update x's relationship directly to the root
        parity[x] ^= par;

        // Path compression
        p[x] = root;

        return {p[x], parity[x]};
    }

    // Connects a and b with a required relationship:
    //
    // x = 0 -> a and b must be the same
    // x = 1 -> a and b must be different
    //
    // Returns false if this connection creates a contradiction
    bool unite(int a, int b, int x)
    {
        auto [ra, pa] = find(a);
        auto [rb, pb] = find(b);

        // Already connected
        if (ra == rb)
            return (pa ^ pb) == x;

        // Attach smaller component to larger component
        if (sz[ra] < sz[rb])
        {
            swap(ra, rb);
            swap(pa, pb);
        }

        p[rb] = ra;

        // Store relationship between the two components
        parity[rb] = pa ^ pb ^ x;

        sz[ra] += sz[rb];

        return true;
    }

    // Returns true if a and b are in the same component
    // and are known to have the same color
    bool sameColor(int a, int b)
    {
        auto [ra, pa] = find(a);
        auto [rb, pb] = find(b);

        if (ra != rb)
            return false;

        return (pa ^ pb) == 0;
    }

    // Returns true if a and b are in the same component
    // and are known to have different colors
    bool differentColor(int a, int b)
    {
        auto [ra, pa] = find(a);
        auto [rb, pb] = find(b);

        if (ra != rb)
            return false;

        return (pa ^ pb) == 1;
    }
};




// DSU Rollback
// Allows merging components and then undoing merges.
//
// Important:
//   - No path compression.
//   - Uses union by size.
//
// Typical use:
//   Segment Tree over time + DSU Rollback

struct DSU
{
    vector<int> p, sz;
    vector<pair<int, int>> history;

    DSU(int n)
    {
        p.resize(n);
        sz.assign(n, 1);

        iota(p.begin(), p.end(), 0);
    }

    int find(int x)
    {
        // No path compression!
        while (p[x] != x)
            x = p[x];

        return x;
    }

    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);

        if (a == b)
        {
            history.push_back({-1, -1});
            return false;
        }

        if (sz[a] < sz[b])
            swap(a, b);

        // Save state before merging
        history.push_back({b, sz[a]});

        p[b] = a;
        sz[a] += sz[b];

        return true;
    }

    // Save current state
    int snapshot()
    {
        return history.size();
    }

    // Undo until reaching a previous snapshot
    void rollback(int snap)
    {
        while ((int)history.size() > snap)
        {
            auto [b, oldSize] = history.back();
            history.pop_back();

            if (b == -1)
                continue;

            int a = p[b];

            p[b] = b;
            sz[a] = oldSize;
        }
    }
};