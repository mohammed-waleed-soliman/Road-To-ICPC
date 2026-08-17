struct LCA {
    int n, LOG;
    vector<int> depth;
    vector<vector<int>> up;

    void build(vector<vector<int>>& adj, int root) {
        n = adj.size();
        LOG = 1 + (int)log2(n);

        depth.assign(n, 0);
        up.assign(n, vector<int>(LOG));

        dfs(root, root, adj);
    }

    void dfs(int node, int parent, vector<vector<int>>& adj) {
        up[node][0] = parent;

        for (int j = 1; j < LOG; j++) {
            up[node][j] = up[up[node][j-1]][j-1];
        }

        for (auto i : adj[node]) {
            if (i == parent) continue;

            depth[i] = depth[node] + 1;
            dfs(i, node, adj);
        }
    }

    int get_kt(int node,int k)
    {
        int ans = node;
        for (int j = 0; j < LOG; j++)
        {
            if ((k >> j) & 1)
                ans = up[ans][j];
        }
        return ans;
    }

    int lca(int a,int b)
    {
        if(depth[b] > depth[a])
            swap(a,b);

        a = get_kt(a, depth[a] - depth[b]);

        if (a == b)
            return a;

        for (int j = LOG - 1; j >= 0; j--)
        {
            if(up[a][j] != up[b][j])
                a = up[a][j],b = up[b][j];
        }

        return up[a][0];
    }
};



// get max weight in paths
struct LCA {
    int n, LOG;
    vector<int> depth;
    vector<vector<int>> up;
    vector<vector<int>> sp;

    void build(vector<vector<pair<int,int>>>& adj, int root) {
        n = adj.size();
        LOG = 32 - __builtin_clz(n);

        depth.assign(n, 0);
        up.assign(n, vector<int>(LOG,root));
        sp.assign(n, vector<int>(LOG,0));

        dfs(root, root, 0, adj);
    }

    void dfs(int node, int parent,int w, vector<vector<pair<int,int>>>& adj) {
        up[node][0] = parent;
        sp[node][0] = w;
        for (int j = 1; j < LOG; j++) {
            up[node][j] = up[up[node][j-1]][j-1];
            sp[node][j] = max(sp[node][j-1],sp[up[node][j-1]][j-1]);
        }

        for (auto i : adj[node]) {
            if (i.first == parent) continue;

            depth[i.first] = depth[node] + 1;
            dfs(i.first, node, i.second, adj);
        }
    }

    int get_kt(int node,int k)
    {
        int ans = node;
        for (int j = 0; j < LOG; j++)
        {
            if ((k >> j) & 1)
                ans = up[ans][j];
        }
        return ans;
    }
    
    int get_mx(int node,int k)
    {
        int ans = 0;
        for (int j = 0; j < LOG; j++)
        {
            if((k>>j)&1)
            {
                ans = max(ans,sp[node][j]);
                node = up[node][j];
            }
        }
        return ans;
    }

    int lca(int a,int b)
    {
        if(depth[b] > depth[a])
            swap(a,b);

        a = get_kt(a, depth[a] - depth[b]);

        if (a == b)
            return a;

        for (int j = LOG - 1; j >= 0; j--)
        {
            if(up[a][j] != up[b][j])
                a = up[a][j],b = up[b][j];
        }

        return up[a][0];
    }

    int gt_mx_path(int a,int b)
    {
        int lc = lca(a,b);
        return max(get_mx(a,depth[a]-depth[lc]),get_mx(b,depth[b]-depth[lc]));
    }
};