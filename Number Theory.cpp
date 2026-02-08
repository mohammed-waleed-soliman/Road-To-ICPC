#include <bits/stdc++.h>
using namespace std;

bool is_prime(long long x){
  if (x == 2)
  {
    return true;
  }
  if (x < 2 || x % 2 == 0)
  {
    return false;
  }
  for (long long i = 3; i*i <= x; i+=2)
  {
    if (x % i == 0)
    {
      return false;
    }
  }
  return true;
}

vector<long long> get_divisors(long long n)
{
  vector <long long> res;
  for (long long i = 1; i*i <= n; i++)
  {
    if(i*i==n) res.push_back(i);
    else if(n%i==0)
    {
      res.push_back(i);
      res.push_back(n/i);
    }
  }
  sort(res.begin(),res.end());
  return res;
}

long long gcd(long long x, long long y)
{
  if(x<y) swap(x,y);
  if(y==0) return x;
  return gcd(y,x%y);
}

long long lcm(long long x, long long y)
{
  return (x*y)/gcd(x,y);
}



















































// #include <bits/stdc++.h>
// #include <fstream>
// const double pi = acos(-1.0);
// const long long MOD = 1e9+7;
// #define ll long long
// #define ld long double
// #define sortx(X) sort(X.begin(),X.end());
// #define el "\n"
// #define yes cout<<"YES"<<el;
// #define no cout<<"NO"<<el;
// #define imp cout<<"-1"<<el;
// #define Y_N if(cond){yes}else{no}
// #define MW_YH ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// using namespace std;
// // ----------------------------Functions---------------------------- //
// void Mohammed_Waleed(){
//   MW_YH
//   // #ifndef ONLINE_JUDGE
//   //   freopen("input.txt", "r", stdin);
//   //   freopen("output.txt", "w", stdout);
//   // #endif
// }
// // ----------------------------------------------------------------- //
// ll dp[104][4];
// ll ICPC(vector<ll>&v, ll ind, ll res, ll last){
//   if(ind==v.size()) return res;
//   if(v[ind]==0)
//   {
//     if(dp[ind][0]) return dp[ind][0];
//     return dp[ind][0] = ICPC(v,ind+1,res+1,0); // rest
//   }
//   else if(v[ind]==1)
//   {
//     ll a, b = LONG_LONG_MAX;
//     if(dp[ind][0]) a = dp[ind][0];
//     else
//     {
//       a = ICPC(v,ind+1,res+1,0); // rest
//       dp[ind][0] = a;
//     }
//     if(last!=1)
//     {
//       if(dp[ind][1]) b = dp[ind][1];
//       else
//       {
//         b = ICPC(v,ind+1,res,1); // contest
//         dp[ind][1] = b;
//       }
//     }
//     return min(a,b);
//   }
//   else if(v[ind]==2)
//   {
//     ll a, b = LONG_LONG_MAX;
//     if(dp[ind][0]) a = dp[ind][0];
//     else
//     {
//       a = ICPC(v,ind+1,res+1,0); // rest
//       dp[ind][0] = a;
//     }
//     if(last!=2)
//     {
//       if(dp[ind][2]) b = dp[ind][2];
//       else
//       {
//         b = ICPC(v,ind+1,res,2); // gym
//         dp[ind][2] = b;
//       }
//     }
//     return min(a,b);
//   }
//   else
//   {
//     ll a, b = LONG_LONG_MAX, c = LONG_LONG_MAX;
//     if(dp[ind][0]) a = dp[ind][0];
//     else
//     {
//       a = ICPC(v,ind+1,res+1,0); // rest
//       dp[ind][0] = a;
//     }
//     if(last!=1)
//     {
//       if(dp[ind][1]) b = dp[ind][1];
//       else
//       {
//         b = ICPC(v,ind+1,res,1); // contest
//         dp[ind][1] = b;
//       }
//     }
//     if(last!=2)
//     {
//       if(dp[ind][2]) c = dp[ind][2];
//       else
//       {
//         c = ICPC(v,ind+1,res,2); // gym
//         dp[ind][2] = c;
//       }
//     }
//     return min({a,b,c});
//   }
// }
// void solution(){
//   ll size;
//   cin >> size;
//   vector<ll>v(size);
//   for(ll i = 0; i < size; i++) cin >> v[i];
//   ll res = ICPC(v,0,0,0);
//   cout << res;
// }

// int main(){
//   Mohammed_Waleed();
//   int ntimes = 1;
//   // cin >> ntimes;
//   while (ntimes--)
//   {
//     solution();
//   }
// }

/*
#include <bits/stdc++.h>
#include <fstream>
const double pi = acos(-1.0);
const long long MOD = 1e9+7;
#define ll long long
#define ld long double
#define sortx(X) sort(X.begin(),X.end());
#define el "\n"
#define yes cout<<"YES"<<el;
#define no cout<<"NO"<<el;
#define imp cout<<"-1"<<el;
#define Y_N if(cond){yes}else{no}
#define MW_YH ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// ----------------------------Functions---------------------------- //
void Mohammed_Waleed(){
  MW_YH
  // #ifndef ONLINE_JUDGE
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", stdout);
  // #endif
}
// ----------------------------------------------------------------- //
ll ICPC(vector<ll>&v, ll ind, ll res, ll last){
  if(ind==v.size()) return res;
  if(v[ind]==0)
  {
    return ICPC(v,ind+1,res+1,0); // rest
  }
  else if(v[ind]==1)
  {
    ll a = ICPC(v,ind+1,res+1,0); // rest
    ll b = LONG_LONG_MAX;
    if(last!=1) b = ICPC(v,ind+1,res,1); // contest
    return min(a,b);
  }
  else if(v[ind]==2)
  {
    ll a = ICPC(v,ind+1,res+1,0); // rest
    ll b = LONG_LONG_MAX;
    if(last!=2) b = ICPC(v,ind+1,res,2); // gym
    return min(a,b);
  }
  else
  {
    ll a = ICPC(v,ind+1,res+1,0); // rest
    ll b = LONG_LONG_MAX;
    ll c = LONG_LONG_MAX;
    if(last!=1) b = ICPC(v,ind+1,res,1); // contest
    if(last!=2) c = ICPC(v,ind+1,res,2); // gym
    return min({a,b,c});
  }
}
void solution(){
  ll size;
  cin >> size;
  vector<ll>v(size);
  for(ll i = 0; i < size; i++) cin >> v[i];
  ll res = ICPC(v,0,0,0);
  cout << res;
}

int main(){
  Mohammed_Waleed();
  int ntimes = 1;
  // cin >> ntimes;
  while (ntimes--)
  {
    solution();
  }
}
*/