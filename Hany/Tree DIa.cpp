// Returns the tree diameter in number of edges
// Time: O(N)

pair<int,int> dfs_diameter(int v, int p, vector<vector<int>> &adj)
{
    pair<int,int> best = {0, v};

    for (int u : adj[v])
    {
        if (u == p)
            continue;

        auto cur = dfs_diameter(u, v, adj);
        cur.first++;

        if (cur.first > best.first)
            best = cur;
    }

    return best;
}

int tree_diameter(vector<vector<int>> &adj)
{
    auto first = dfs_diameter(0, -1, adj);
    auto second = dfs_diameter(first.second, -1, adj);

    return second.first;
}