#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
int n, m;
long long grid[N][N], dp[N][N];
long long GridPath(int i, int j)
{
    if(i==n-1 && j==m-1) return grid[i][j];
    if(i>=n || j>=m) return INT_MAX;
    long long &ret = dp[i][j];
    if(ret!=-1) return ret;
    return ret=grid[i][j]+min(GridPath(i,j+1),GridPath(i+1,j));
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];
    memset(dp,-1,sizeof dp);
    cout << GridPath(0,0);
}
