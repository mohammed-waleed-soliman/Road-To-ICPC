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

void RadixSort(vector<long long>&arr)
{
  // Time Complexity: O(d⋅n)
  int size = arr.size();
  long long mx = *max_element(arr.begin(),arr.end());
  for(int place = 1; mx/place > 0; place*=10)
  {
    vector<int>count(10,0);
    vector<long long>temp(size);
    for(int i = 0; i < size; i++) count[(arr[i]/place)%10]++;
    for(int i = 1; i < 10; i++) count[i]+=count[i-1];
    for(int i = size-1; i >=0; i--)
    {
      temp[count[(arr[i]/place)%10]-1]=arr[i];
      count[(arr[i]/place)%10]--;
    }
    swap(arr,temp);
  }
}

vector<long long> merge(vector<long long>&left, vector<long long>&right)
{
  int i = 0, j = 0;
  int n = left.size(), m = right.size();
  vector<long long> res;
  while(i<n && j<m)
  {
    if(left[i]<right[j]) res.push_back(left[i++]);
    else res.push_back(right[j++]);
  }
  while(i<n) res.push_back(left[i++]);
  while(j<m) res.push_back(right[j++]);
  return res;
}
vector<long long> MergeSort(int i, int j, vector<long long>&arr)
{
  // Time Complexity: O(n.log(n))
  if(i==j) return {arr[i]};
  int mid = (i+j)>>1;
  vector<long long> left = MergeSort(i,mid,arr);
  vector<long long> right = MergeSort(mid+1,j,arr);
  return merge(left,right);
}
/*Mohammed Waleed*/