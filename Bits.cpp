#include <bits/stdc++.h>
using namespace std;

bool knowBit(long long val, long long ind){
  return (val>>ind)&1;
}
int count_on_bits(long long val){
  int ret = 0;
  for (int i = 0; i < 64; i++) // optimize into 32 for integer values
  {
    if((val>>i)&1) ret++;
  }
  return ret;
}
long long setBit (long long val, long long ind, bool bit){
  if(bit) val |= (1<<ind);
  else val &= (~(1<<ind));
  return val;
}
long long changeBit(long long val, long long ind){
  val ^= (1<<ind);
  return val;
}

// x/(2^k) ==> x>>k
// x*(2^k) ==> x<<k