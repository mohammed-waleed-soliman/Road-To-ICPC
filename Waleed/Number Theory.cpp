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