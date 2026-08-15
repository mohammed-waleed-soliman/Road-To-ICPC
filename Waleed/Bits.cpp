#include <bits/stdc++.h>
using namespace std;

bool knowBit(long long val, long long ind){
  return (val>>ind)&1LL;
}
int count_on_bits(long long val){
  int ret = 0;
  for (int i = 0; i < 64; i++) // optimize into 32 for integer values
  {
    if((val>>i)&1LL) ret++;
  }
  return ret;
}
long long setBit (long long val, long long ind, bool bit){
  if(bit) val |= (1LL<<ind);
  else val &= (~(1LL<<ind));
  return val;
}
long long changeBit(long long val, long long ind){
  val ^= (1LL<<ind);
  return val;
}
bool powerOf2(long long x){
  return x && !(x&(x-1LL));
}
/*
BITWISE TRICKS:
- x/(2^k) ==> x>>k
- x*(2^k) ==> x<<k
- x%(2^k) ==> x&((2^k)-1)

if:
  no. of set bits in A = X
  no. of set bits in B = Y
  no. of set bits in (A^B) = Z
then:
  Z is even if X+Y is even
  Z is odd if X+Y is odd

instead of:
  if(X==A) X=B
  else if(X==B) X=A
do:
  X=A^B^X

A+B = (A^B) + 2*(A&B)
A+B = (A|B) + (A&B)

no. of set bits in x:
  __builtin_popcount(x) if x is int
  __builtin_popcountll(x) if x is long long
*/