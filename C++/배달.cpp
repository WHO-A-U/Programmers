#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;

vector<pair<int,int>> e[51];
int d[51];
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    for(int i=0;i<51;i++)
        d[i]=INF;
    
    for(int i=0;i<road.size();i++){
        int a = road[i][0];
        int b = road[i][1];
        int c = road[i][2];
        e[a].push_back({b,c});
        e[b].push_back({a,c});
    }
    
    queue<int> q;
    q.push(1);
    d[1]=0;
    while(!q.empty()){
        int cur = q.front();
        int cost = d[cur];
        q.pop();
        for(int i=0;i<e[cur].size();i++){
            int next = e[cur][i].first;
            int dist = e[cur][i].second;
            if(cost+dist<d[next]){
                d[next]=cost+dist;
                q.push(next);
            }
        }
    }
    
    
    for(int i=1;i<=N;i++){
        if(d[i]<=K)answer++;
    }
    
    return answer;
}