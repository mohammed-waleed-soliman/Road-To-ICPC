// Flood fill: visits all connected cells with the same value
// Returns the size of the connected component
ll floodFill(const vector<vector<ll>> &grid, vector<vector<bool>> &vis,
             ll r, ll c)
{
    int n = grid.size();
    int m = grid[0].size();

    if (r < 0 || r >= n || c < 0 || c >= m)
        return 0;

    if (vis[r][c])
        return 0;

    vis[r][c] = true;

    ll sz = 1;

    sz += floodFill(grid, vis, r + 1, c);
    sz += floodFill(grid, vis, r - 1, c);
    sz += floodFill(grid, vis, r, c + 1);
    sz += floodFill(grid, vis, r, c - 1);

    return sz;
}

// Flood fill: visits all connected cells having the same value as (r, c)
// Returns the size of the connected component
ll floodFill(const vector<vector<ll>> &grid, vector<vector<bool>> &vis,
             ll r, ll c)
{
    int n = grid.size();
    int m = grid[0].size();

    if (r < 0 || r >= n || c < 0 || c >= m)
        return 0;

    if (vis[r][c])
        return 0;

    ll color = grid[r][c];
    vis[r][c] = true;

    ll sz = 1;

    if (r + 1 < n && grid[r + 1][c] == color)
        sz += floodFill(grid, vis, r + 1, c);

    if (r - 1 >= 0 && grid[r - 1][c] == color)
        sz += floodFill(grid, vis, r - 1, c);

    if (c + 1 < m && grid[r][c + 1] == color)
        sz += floodFill(grid, vis, r, c + 1);

    if (c - 1 >= 0 && grid[r][c - 1] == color)
        sz += floodFill(grid, vis, r, c - 1);

    return sz;
}

// Finds the size of every connected component
vector<ll> allComponents(const vector<vector<ll>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<ll> sizes;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j])
                sizes.push_back(floodFill(grid, vis, i, j));
        }
    }

    return sizes;
}


// Visits all connected cells having the given color		
ll floodFill(const vector<vector<ll>> &grid, vector<vector<bool>> &vis,
             ll r, ll c, ll color)
{
    int n = grid.size();
    int m = grid[0].size();

    if (r < 0 || r >= n || c < 0 || c >= m)
        return 0;

    if (vis[r][c] || grid[r][c] != color)
        return 0;

    vis[r][c] = true;

    return 1
        + floodFill(grid, vis, r + 1, c, color)
        + floodFill(grid, vis, r - 1, c, color)
        + floodFill(grid, vis, r, c + 1, color)
        + floodFill(grid, vis, r, c - 1, color);
}