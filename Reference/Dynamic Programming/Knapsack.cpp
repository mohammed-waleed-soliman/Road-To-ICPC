#include <bits/stdc++.h>
using namespace std;
int n,x;
const int N = 1e5+7;
const int M = 1e2+7;
int arr[N];
int dp[N][M];
int knapSack(int i, int sum)
{
    if(i==n)
    {
        if(sum%x==0) return 1;
        else return 0;
    }
    int &ret = dp[i][sum];
    if(ret!=-1) return ret;
    return ret = knapSack(i+1,(sum+arr[i])%x)+knapSack(i+1,sum);
}
int main()
{
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> arr[i];
    memset(dp,-1,sizeof dp);
    cout << knapSack(0,0);
}
// Knapsack style
// Take or Leave style
// Subset style