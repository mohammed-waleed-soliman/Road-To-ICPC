#include <bits/stdc++.h>
using namespace std;
struct Node
{
  long long sum;
  Node()
  {
    sum = 0;
  }
  Node(long long x)
  {
    sum = x;
  }
  void change(long long x)
  {
    sum = x;
  }
};
struct SegmentTree
{
  int treeSize;
  vector<Node>Tree;
  SegmentTree(int size)
  {
    treeSize = 1;
    while(treeSize < size) treeSize *= 2;
    Tree.assign(2*treeSize,Node());
  }
  Node merge(Node &left, Node &right)
  {
    return Node(left.sum+right.sum);
  }
  void set(int ind, int val, int ni, int lx, int rx)
  {
    if(rx-lx==1)
    {
      Tree[ni].change(val);
      return;
    }
    int mid = (lx+rx)/2;
    if(ind < mid)
    {
      set(ind,val,2*ni+1,lx,mid);
    }
    else
    {
      set(ind,val,2*ni+2,mid,rx);
    }
    Tree[ni] = merge(Tree[2*ni+1],Tree[2*ni+2]);
  }
  void set(int ind, int val)
  {
    set(ind,val,0,0,treeSize);
  }
  Node get(int l, int r, int ni, int lx, int rx)
  {
    if(lx>=l && rx<=r)
    {
      return Tree[ni];
    }
    if(lx>=r || rx<=l)
    {
      return Node();
    }
    int mid = (lx+rx)/2;
    Node left = get(l,r,2*ni+1,lx,mid);
    Node right = get(l,r,2*ni+2,mid,rx);
    return merge(left,right);
  }
  int get(int l, int r)
  {
    return get(l,r,0,0,treeSize).sum;
  }
};