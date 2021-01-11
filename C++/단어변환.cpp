#include <string>
#include <vector>
#include<queue>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

int dist[51];
vector<int> node[51];
bool isPossible(string a , string b){
    int cnt=0;
    for(int i=0;i<a.size();i++)if(a[i]==b[i])cnt++;
    return a.size()-cnt==1?true:false;
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0,n = words.size(),idx=-1;
    for(int i=0;i<n;i++)if(words[i]==target)idx=i;
    if(idx==-1)return 0;
    words.push_back(begin);
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(isPossible(words[i],words[j])){
                node[i].push_back(j);
                node[j].push_back(i);
            }
        }
    }
    for(int i=0;i<n;i++)dist[i]=-1;
    queue<int> q;
    q.push(n);
    dist[n]=0;
    while(!q.empty()){
        int cur = q.front();
        int curDist = dist[cur];
        q.pop();
        for(int i=0;i<node[cur].size();i++){
            int& nextDist = dist[node[cur][i]];
            if(nextDist==-1||nextDist>curDist+1){
                nextDist=curDist+1;
                q.push(node[cur][i]);
            }
        }
    }
    return dist[idx]!=-1?dist[idx]:0;
}