// Remove masks that are useless:
// If mask A is a subset of mask B, then A is never better than B.
// We only keep maximal (non-dominated) masks.

vector<int> getUsefulMasks(const vector<int>& a, int m)
{
    int SZ = 1 << m;

    // Which masks actually exist?
    vector<bool> present(SZ, false);
    for (int mask : a)
        present[mask] = true;

    // hasSuperset[mask] = does there exist a present mask
    // that contains every bit of 'mask'?
    vector<bool> hasSuperset = present;

    // Superset DP
    for (int bit = 0; bit < m; bit++)
    {
        for (int mask = 0; mask < SZ; mask++)
        {
            if (!(mask & (1 << bit)))
            {
                hasSuperset[mask] |=
                    hasSuperset[mask | (1 << bit)];
            }
        }
    }

    vector<int> useful;

    // A mask is dominated if we can add at least one bit
    // and still find a present mask containing it.
    for (int mask : a)
    {
        if (!present[mask])
            continue;

        bool dominated = false;

        for (int bit = 0; bit < m; bit++)
        {
            if (!(mask & (1 << bit)))
            {
                if (hasSuperset[mask | (1 << bit)])
                {
                    dominated = true;
                    break;
                }
            }
        }

        if (!dominated)
            useful.push_back(mask);
    }

    sort(useful.begin(), useful.end());
    useful.erase(unique(useful.begin(), useful.end()), useful.end());

    return useful;
}



// Minimum number of masks needed to obtain the full mask using OR.

int minMasksToReach(const vector<int>& useful, int target, int m)
{
    int SZ = 1 << m;

    vector<int> dist(SZ, -1);
    queue<int> q;

    dist[0] = 0;
    q.push(0);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == target)
            return dist[cur];

        for (int mask : useful)
        {
            int nxt = cur | mask;

            // Don't allow bits outside target
            if ((mask & ~target) != 0)
                continue;

            if (dist[nxt] == -1)
            {
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }

    return -1;
}


// Iterate over all submasks of mask
for (ll sub = mask; ; sub = (sub - 1) & mask)
{
    // use sub

    if (sub == 0)
        break;
}


// Bitmask DP / TSP
// Finds the minimum distance to start from a node and visit ALL important nodes.
// dist[i][j] = shortest distance between important nodes i and j.
// dp[mask][i] = minimum distance after visiting mask and ending at i.

ll tsp(vector<vector<ll>> &dist, int start)
{
    int n = dist.size();
    int sz = 1 << n;

    vector<vector<ll>> dp(sz, vector<ll>(n, INF));

    dp[1 << start][start] = 0;

    for (int mask = 0; mask < sz; mask++)
    {
        for (int i = 0; i < n; i++)
        {
            if (!(mask & (1 << i)))
                continue;

            for (int j = 0; j < n; j++)
            {
                if (mask & (1 << j))
                    continue;

                dp[mask | (1 << j)][j] =
                    min(dp[mask | (1 << j)][j],
                        dp[mask][i] + dist[i][j]);
            }
        }
    }

    ll ans = INF;

    for (int i = 0; i < n; i++)
        ans = min(ans, dp[sz - 1][i]);

    return ans;
}


// Dijkstra + Bitmask DP
// Used when there are few important nodes (K <= ~15).
// dp[mask][i] = best result after visiting mask, currently at i.
// First find shortest distances between all important nodes.

vector<vector<ll>> dijkstra_all(vector<vector<pair<ll,ll>>> &adj,
                                vector<int> &nodes)
{
    int n = adj.size();
    int k = nodes.size();

    vector<vector<ll>> dist(k, vector<ll>(k, INF));

    for (int s = 0; s < k; s++)
    {
        vector<ll> d(n, INF);
        priority_queue<pair<ll,ll>,
                       vector<pair<ll,ll>>,
                       greater<pair<ll,ll>>> pq;

        d[nodes[s]] = 0;
        pq.push({0, nodes[s]});

        while (!pq.empty())
        {
            auto [du, u] = pq.top();
            pq.pop();

            if (du != d[u])
                continue;

            for (auto [v, w] : adj[u])
            {
                if (d[v] > du + w)
                {
                    d[v] = du + w;
                    pq.push({d[v], v});
                }
            }
        }

        for (int i = 0; i < k; i++)
            dist[s][i] = d[nodes[i]];
    }

    return dist;
}


// Bitmask DP
// dp[mask][i] = best value after visiting mask and ending at i.

ll bitmask_dp(vector<vector<ll>> &dist, vector<ll> &value)
{
    int k = value.size();
    int sz = 1 << k;

    vector<vector<ll>> dp(sz, vector<ll>(k, -INF));

    for (int i = 0; i < k; i++)
        dp[1 << i][i] = value[i];

    ll ans = 0;

    for (int mask = 1; mask < sz; mask++)
    {
        for (int i = 0; i < k; i++)
        {
            if (!(mask & (1 << i)))
                continue;

            for (int j = 0; j < k; j++)
            {
                if (mask & (1 << j))
                    continue;

                int nxt = mask | (1 << j);

                dp[nxt][j] = max(
                    dp[nxt][j],
                    dp[mask][i] - dist[i][j] + value[j]
                );
            }

            ans = max(ans, dp[mask][i]);
        }
    }

    return ans;
}
