#include <bits/stdc++.h>
using namespace std;

vector <long long> dijkstra(long long n, long long source, map<long long,vector<pair<long long,long long>>>&adj)
{
  vector<long long>res(n+1,LONG_LONG_MAX);
  vector<bool>vis(n+1);
  res[source]=0;
  function<bool(pair<long long,long long>,pair<long long,long long>)> cmp = [](pair<long long,long long>a,pair<long long,long long>b){return a.second>b.second;};
  priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,decltype(cmp)>pq(cmp);
  pq.push({source,0});
  while (!pq.empty())
  {
    for(auto neg:adj[pq.top().first])
    {
      if(res[neg.first]>neg.second+res[pq.top().first])
      {
        res[neg.first]=neg.second+res[pq.top().first];
        pq.push({neg.first,res[neg.first]});
      }
    }
    vis[pq.top().first]=1;
    while (!pq.empty() && vis[pq.top().first]) pq.pop();
  }
  return res;
}

// Dijkstra with Path Tracking
vector<pair<long long,long long>>dijkstra_path(long long n, long long source, map<long long,vector<pair<long long,long long>>>&adj)
{
  vector<pair<long long,long long>>res(n+1,{LONG_LONG_MAX,-1});
  vector<bool>vis(n+1);
  res[source].first=0;
  function<bool(pair<long long,long long>,pair<long long,long long>)> cmp = [](pair<long long,long long>a,pair<long long,long long>b){return a.second>b.second;};
  priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,decltype(cmp)>pq(cmp);
  pq.push({source,0});
  while (!pq.empty())
  {
    for(auto neg:adj[pq.top().first])
    {
      if(res[neg.first].first>neg.second+res[pq.top().first].first)
      {
        res[neg.first].first=neg.second+res[pq.top().first].first;
        res[neg.first].second=pq.top().first;
        pq.push({neg.first,res[neg.first].first});
      }
    }
    vis[pq.top().first]=1;
    while (!pq.empty() && vis[pq.top().first]) pq.pop();
  }
  return res;
}