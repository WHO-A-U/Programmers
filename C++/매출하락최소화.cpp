#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
using ll = long long;
vector<int> node[300001];
int cost[300001];
long long d[300001][2];
pair<ll,ll> go(int curNode){
    if(node[curNode].size()==0){
        return {cost[curNode],INF};
    }
    vector<pair<ll,ll>> tmp;
    ll fs=cost[curNode], sc=0;
    for(int i=0;i<node[curNode].size();i++){
        tmp.push_back(go(node[curNode][i]));
    }
    for(int i=0;i<tmp.size();i++){
        if(tmp[i].second!=INF)
            fs+=min(tmp[i].first,tmp[i].second);
    }
    ll minVal =INF,minDiff = INF;
    int idx;
    bool flag=false,onlyLeaf=true;
    for(int i=0;i<tmp.size();i++){
        if(tmp[i].second!=INF){
            onlyLeaf = false;
            if(tmp[i].first<=tmp[i].second){
                flag=true;
            }
            else{
                minDiff = min(minDiff , tmp[i].first - tmp[i].second);
            }
            sc+=min(tmp[i].first,tmp[i].second);
        }else{
            minVal=min(minVal  , tmp[i].first);
        }
    }
    if(onlyLeaf)sc=minVal;
    else{
        if(!flag){
            if(onlyLeaf){
                sc+=minDiff;
            }else{
                sc+=min(minDiff , minVal);
            }
        }
    }
    return {fs,sc};
}
int solution(vector<int> sales, vector<vector<int>> links) {
    memset(d,0,sizeof(d));
    for(int i=0;i<sales.size();i++){
        cost[i+1]=sales[i];
    }
    for(int i=0;i<links.size();i++){
        int a = links[i][0];
        int b = links[i][1];
        node[a].push_back(b);
    }
    pair<ll,ll> ans = go(1);
    
    return min(ans.first,ans.second);
}