#include <bits/stdc++.h>
using namespace std;

void BubbleSort(vector<long long>&v){
  // Time Complexity: O(n2)
  long long size = v.size();
  for (long long i = 0; i < size-1; i++)
  {
    bool is_swapped = false;
    for(long long j = 0; j < size-1-i; j++)
    {
      if(v[j]>v[j+1])
      {
        long long temp = v[i];
        v[i] = v[i + 1];
        v[i + 1] = temp;
        is_swapped = true;
      }
    }
    if(!is_swapped) break;
  }
}

void SelectionSort(vector<long long>&v){
  // Time Complexity: O(n2)
  long long size = v.size();
  for (long long i = 0; i < size-1; i++)
  {
    long long ind = i;
    for(long long j = i+1; j < size; j++)
    {
      if(v[j]<v[ind]) ind = j;
    }
    if(i!=ind)
    {
      int temp = v[i];
      v[i] = v[ind];
      v[ind] = temp;
    }
  }
}

void InsertionSort(vector<long long>&v){
  // Time Complexity: O(n2)
  long long size = v.size();
  for (long long i = 1; i < size; i++)
  {
    long long key = v[i];
    int j = i-1;
    while(j>=0 && key<v[j])
    {
      v[j+1] = v[j];
      j--;
    }
    v[j+1] = key;
  }
}

void CountingSort(vector<long long>&v){
  // Time Complexity: O(n+max)
  long long mx = v[0];
  long long size = v.size();
  for(long long i = 1; i < size; i++) mx = max(mx,v[i]);
  vector<long long>count(mx+1,0);
  for(auto i:v) count[i]++;
  for(long long i = 1; i <= mx; i++) count[i] += count[i-1];
  vector<long long>output(size);
  for(long long i = 0; i < size; i++)
  {
    output[count[v[i]]-1] = v[i];
    count[v[i]]--;
  }
  v = output;
}