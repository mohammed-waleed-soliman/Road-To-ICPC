// Visits all nodes reachable from u
void dfs(const vector<vector<ll>> &adj, vector<bool> &vis, ll u)
{
    vis[u] = true;

    for (ll v : adj[u])
    {
        if (!vis[v])
            dfs(adj, vis, v);
    }
}


// Returns the size of u's connected component
ll componentSize(const vector<vector<ll>> &adj, vector<bool> &vis, ll u)
{
    vis[u] = true;

    ll ans = 1;

    for (ll v : adj[u])
    {
        if (!vis[v])
            ans += componentSize(adj, vis, v);
    }

    return ans;
}


// Checks if the graph is connected
bool isConnected(const vector<vector<ll>> &adj, ll start = 1)
{
    vector<bool> vis(adj.size(), false);

    dfs(adj, vis, start);

    for (int i = 1; i < adj.size(); i++)
    {
        if (!vis[i])
            return false;
    }

    return true;
}

// Checks if the graph is bipartite
bool dfsColor(const vector<vector<ll>> &adj, vector<int> &color, ll u)
{
    for (ll v : adj[u])
    {
        if (color[v] == -1)
        {
            color[v] = color[u] ^ 1;

            if (!dfsColor(adj, color, v))
                return false;
        }
        else if (color[v] == color[u])
        {
            return false;
        }
    }

    return true;
}

// Checks if the whole graph is bipartite
bool isBipartite(const vector<vector<ll>> &adj)
{
    vector<int> color(adj.size(), -1);

    for (int i = 1; i < adj.size(); i++)
    {
        if (color[i] == -1)
        {
            color[i] = 0;

            if (!dfsColor(adj, color, i))
                return false;
        }
    }

    return true;
}