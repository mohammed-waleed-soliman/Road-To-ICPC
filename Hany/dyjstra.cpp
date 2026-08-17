// Shortest paths from s in a graph with non-negative edge weights
vector<ll> dijkstra(int s, const vector<vector<pair<ll,ll>>> &adj)
{
    vector<ll> dist(adj.size(), INF);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u])
            continue;

        for (auto [v, w] : adj[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

// Shortest paths + parent of each node in the shortest path
vector<ll> dijkstra(int s, const vector<vector<pair<ll,ll>>> &adj, vector<ll> &prev)
{
    vector<ll> dist(adj.size(), INF);
    prev.assign(adj.size(), -1);

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u])
            continue;

        for (auto [v, w] : adj[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}


// Finds the shortest distance to every node
// from the closest node in 'sources'
vector<ll> multiDijkstra(const vector<ll> &sources,
                         const vector<vector<pair<ll,ll>>> &adj)
{
    vector<ll> dist(adj.size(), INF);

    // {distance, node}
    priority_queue<
        pair<ll,ll>,
        vector<pair<ll,ll>>,
        greater<pair<ll,ll>>
    > pq;

    // Start Dijkstra from every source at distance 0
    for (ll s : sources)
    {
        dist[s] = 0;
        pq.push({0, s});
    }

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        // Ignore an old/outdated priority queue entry
        if (d != dist[u])
            continue;

        // Try relaxing every edge from u
        for (auto [v, w] : adj[u])
        {
            if (dist[u] + w < dist[v])
            {
                // Found a shorter path to v
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}


// Dijkstra where each node can have multiple states.
//
// dist[node][state] = shortest distance to reach
// that node while being in that state.
//
// This example uses:
// state = 0 -> special operation not used
// state = 1 -> special operation already used
//
// The special operation here makes one edge cost 0.
vector<vector<ll>> dijkstraState(
    ll s,
    const vector<vector<pair<ll,ll>>> &adj
)
{
    int n = adj.size();

    // Two distances for every node: one for each state
    vector<vector<ll>> dist(n, vector<ll>(2, INF));

    // {distance, node, state}
    priority_queue<
        tuple<ll,ll,ll>,
        vector<tuple<ll,ll,ll>>,
        greater<tuple<ll,ll,ll>>
    > pq;

    // Start at s without using the special operation
    dist[s][0] = 0;
    pq.push({0, s, 0});

    while (!pq.empty())
    {
        auto [d, u, state] = pq.top();
        pq.pop();

        // Ignore an outdated entry
        if (d != dist[u][state])
            continue;

        for (auto [v, w] : adj[u])
        {
            // Move normally without changing the state
            if (d + w < dist[v][state])
            {
                dist[v][state] = d + w;
                pq.push({dist[v][state], v, state});
            }

            // If the operation was not used,
            // use it to make this edge free
            if (state == 0 && d < dist[v][1])
            {
                dist[v][1] = d;
                pq.push({dist[v][1], v, 1});
            }
        }
    }

    return dist;
}


// Shortest paths from (sx, sy) on a weighted grid
void gridDijkstra(ll sx, ll sy,const vector<vector<ll>> &grid,vector<vector<ll>> &dist)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<pair<ll,ll>> moves = {
        {1, 0}, {-1, 0},
        {0, 1}, {0, -1}
    };

    priority_queue<
        pair<ll, pair<ll,ll>>,
        vector<pair<ll, pair<ll,ll>>>,
        greater<pair<ll, pair<ll,ll>>>
    > pq;

    dist.assign(n, vector<ll>(m, INF));

    dist[sx][sy] = grid[sx][sy];
    pq.push({dist[sx][sy], {sx, sy}});

    while (!pq.empty())
    {
        auto [d, pos] = pq.top();
        pq.pop();

        auto [x, y] = pos;

        if (d != dist[x][y])
            continue;

        for (auto [dx, dy] : moves)
        {
            ll nx = x + dx;
            ll ny = y + dy;

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if (dist[x][y] + grid[nx][ny] < dist[nx][ny])
            {
                dist[nx][ny] = dist[x][y] + grid[nx][ny];

                pq.push({
                    dist[nx][ny],
                    {nx, ny}
                });
            }
        }
    }
}