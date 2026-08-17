
ll bellmenford(ll s,ll n,ll m,vector<vector<pair<ll,ll>>> &edges, vector<ll> &dist)
{
    ll q = n - 1;
    dist[s] = 0;
    while(q--)
    {
        for (int i = 0; i < n; i++)
        {
            if(dist[i] == INF)
                continue;
            for (auto j : edges[i])
            {
                ll v = j.first;
                ll w = j.second;
                if(dist[v] > dist[i] + w)
                    dist[v] = dist[i] + w;
            }
        }
    }

    for (int i = 0; i < n; i++)
        {
            if(dist[i] == INF)
                continue;
            for (auto j : edges[i])
            {
                ll v = j.first;
                ll w = j.second;
                if(dist[v] > dist[i] + w)
                    return -1;
            }
        }
        return 1;
}