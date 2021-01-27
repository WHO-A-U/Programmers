#include <bits/stdc++.h>
#define INF 0x3f3f3ff
using namespace std;
vector<pair<int,int>> edge[201];
int dist[201][3];
void shortestPath(int start,int idx,int n){
    bool visit[201];
    int c=n-1;
    memset(visit,false,sizeof(visit));
    dist[start][idx]=0;
    int cur=start,mindist=INF;
    visit[cur]=true;
    while(c--){

        for(int i=0;i<edge[cur].size();i++){
            auto p = edge[cur][i];
            dist[p.first][idx]=min(dist[p.first][idx],p.second+dist[cur][idx]);
        }
        for(int i=1;i<=n;i++){
            if(!visit[i]){
                if(mindist>dist[i][idx]){
                    mindist=dist[i][idx];
                    cur=i;
                }
            }
        }
        visit[cur]=true;
        dist[cur][idx]=mindist;
        mindist=INF;
    }
    return ;
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    for(int i=0;i<=n;i++){
        for(int j=0;j<3;j++){
            dist[i][j]=INF;
        }
    }
    for(int i=0;i<fares.size();i++){
        int from = fares[i][0];
        int to = fares[i][1];
        int cost = fares[i][2];
        edge[from].push_back({to,cost});
        edge[to].push_back({from,cost});
    }
    shortestPath(s,0,n);
    shortestPath(a,1,n);
    shortestPath(b,2,n);
    
    for(int i=1;i<=n;i++){
        answer = min(answer , dist[i][0]+dist[i][1]+dist[i][2]);
    }
    return answer;
}