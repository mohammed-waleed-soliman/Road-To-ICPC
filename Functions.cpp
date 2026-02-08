#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <fstream>
const double pi = acos(-1.0);
#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define sortx(X) sort(X.begin(),X.end());
#define el "\n"
#define yes cout<<"YES"<<el;
#define no cout<<"NO"<<el;
#define imp cout<<"-1"<<el;
#define Y_N if(cond){yes}else{no}
#define fwd(i,a,b) for(int i=a;i<b;i++)
#define bwd(i,a,b) for(int i=a;i>=b;i--)
#define MW_HY ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;
// ----------------------------Functions---------------------------- //
ll string_to_num(char c, string word){
  ll val = 0;
  if (c == 'x')
  {
    for (ll i = 0; i < word.size(); i++)
    {
      val *= 10;
      val += word[i]-48;
    }
  }
  else
  {
    val += c-48;
  }
  return val;
}
ll sigma (ll start, ll end){
  ll res = ((start+end)*(end-start+1)/2);
  return res;
}
ll sigma_odd (ll end){
  return (end+1)*(end+1)/4;
}
ll count_string(string word, string fnd, ll size1, ll size2) {
  ll count = 0;
  ll pos = 0;
  while ((word.find(fnd, pos) != string::npos)&&(pos<size1))
  {
    count++;
    pos = word.find(fnd, pos) + size2;
    if (pos >= size1)
    {
      break;
    }
  }
  return count;
}
ld Gcd(ld x, ld y){
  return fabs(y)<1e-2?x:Gcd(y,fmod(x,y));
}
ld triangle_area(ld a, ld b, ld c){
  ld s = (a+b+c)/2;
  ld res = sqrtf(s*(s-a)*(s-b)*(s-c));
  return res;
}
ld avg(ll size){
  ld val;
  ld sum = 0;
  for (ll i = 0; i < size; i++)
  {
    cin >> val;
    sum += val;
  }
  ld res = sum/size;
  return res;
}
ld distance(ld x1, ld y1, ld x2, ld y2){
  ld d1 = abs(x1-x2), d2 = abs(y1-y2);
  ld dis = sqrtl((d1*d1)+(d2*d2));
  return dis;
}
ld shoelace(ll vertix, ld arr[][2]){
  ld x = 0, y = 0;
  for (ll i = 0; i < vertix; i++)
  {
    x += arr[i][0]*arr[i+1][1];
  }
  for (ll i = 0; i < vertix; i++)
  {
    y += arr[i][1]*arr[i+1][0];
  }
  ld res = abs(x-y)/2;
  return res;
}
string num_to_string(ll val){
  string word = "";
  while (val)
  {
    ll x = val%10;
    word = (char)(x+48) + word;
    val /= 10;
  }
  return word;
}
bool is_prime(ll x){
  if (x == 2)
  {
    return true;
  }
  if (x < 2 || x % 2 == 0)
  {
    return false;
  }
  for (ll i = 3; i*i <= x; i+=2)
  {
    if (x % i == 0)
    {
      return false;
    }
  }
  return true;
}
bool is_palindrom(string word){
  ll start = 0, end = word.size()-1;
  while (start <= end)
  {
    if (word[start] != word[end])
    {
      return false;
    }
    start++, end--;
  }
  return true;
}
void swap(int x, int y){
  int temp = x;
  x = y;
  y = temp;
}
void prime_factorization(ll n, set <ll> & v){
  for (ll i = 1; i <= sqrtl(n); i++)
  {
    if (n % i == 0)
    {
      v.insert(i);
      v.insert((n/i));
    }
  }
}
/*Bits-functions*/
string binary_code(ll x){
  string word = "";
  while (x)
  {
    if (x % 2)
    {
      word = '1' + word;
    }
    else
    {
      word = '0' + word;
    }
    x /= 2;
  }
  return word;
}
bool knowBit(ll val, ll ind){
  return (val>>ind)&1;
}
ll setBit(ll val, ll ind, bool bit){
  if (bit)
  {
    val |= (1<<ind);
  }
  else
  {
    val &= (~(1<<ind));
  }
  return val;
}
ll changeBit(ll val, ll ind){
  val ^= (1<<ind);
  return val;
}
bool is_powerof_2(ll x){
  return x && (!(x&(x-1)));
}
/*Graph-functions*/
map <ll,vector<ll>> adj;
void DFS(int s, vector <bool>&vis)
{
  stack<int> stack;
  stack.push(s);
  while (!stack.empty())
  {
    int m = stack.top();
    stack.pop();
    vis[m] = 1;
    for (auto a : adj[m])
    {
      if (!vis[a]) {
        stack.push(a);
      }
    }
  }
}
ll bfs(ll node, queue <ll>&q, ll t, vector <bool>&vis){
  q.push(node);
  while (!q.empty())
  {
    for (auto i:adj[q.front()])
    {
      if (!vis[i])
      {
        q.push(i);
      }
    }
    vis[q.front()] = 1;
    // the condition acording to the promblem
    q.pop();
  }
  return -1;
}
// ----------------------------------------------------------------- //
void solution(){
  
}

int main(){ MW_HY
  // #ifndef ONLINE_JUDGE
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", stdout);
  // #endif
  int ntimes = 1;
  // cin >> ntimes;
  while (ntimes--)
  {
    solution();
  }
}