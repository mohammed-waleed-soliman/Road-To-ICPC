#include <bits/stdc++.h>
using namespace std;

vector<long long>PrefixSum(vector<long long>&v){
    vector<long long>pre(v.size()+1,0);
    for(int i = 1; i <= v.size(); i++) pre[i] = pre[i-1] + v[i-1];
    return pre;
}

vector<long long>SufixSum(vector<long long>&v){
    vector<long long>suf(v.size()+1,0);
    for(int i = v.size(); i>=0; i--) suf[i] = suf[i+1] + v[i-1];
    return suf;
}

vector<long long>PrefixXor(vector<long long>&v){
    vector<long long>preXor(v.size()+1,0);
    for(int i = 1; i <= v.size(); i++) preXor[i] = preXor[i-1] ^ v[i-1];
    return preXor;
}