void floydwarshall(ll n,vector<vector<ll>> &dist)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if(dist[i][k] == INF)
                continue;
            for (int j = 1; j <= n; j++)
            {
                if(dist[k][j] == INF)
                    continue;
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (dist[i][i] < 0)
        {
            // Negative cycle detected
        }
    }
}