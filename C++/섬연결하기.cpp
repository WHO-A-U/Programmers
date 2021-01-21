#include <string>
#include <vector>
#include<cstring>
#include<algorithm>
#include<iostream>
#define INF 987654321;

using namespace std;


bool visit[101];
int dist[101];
vector<pair<int,int>> edge[101];

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    memset(visit,false,sizeof(visit));
    for(int i=0;i<n;i++)dist[i]=INF;
    for(int i=0;i<costs.size();i++){
        int n1 = costs[i][0];
        int n2 = costs[i][1];
        int cost = costs[i][2];
        edge[n1].push_back({n2,cost});
        edge[n2].push_back({n1,cost});
    }

    int cur=0;
    visit[0]=true;
    for(int i=0;i<n-1;i++){

        for(int j=0;j<edge[cur].size();j++){
            int next = edge[cur][j].first;
            int cost = edge[cur][j].second;
            if(!visit[next]){
                dist[next]=min(dist[next],cost);
            }
        }

        int idx,mindist=INF;
        for(int j=0;j<n;j++){
            if(!visit[j]&&dist[j]<mindist){
                idx=j;
                mindist=dist[j];
                
            }
        }
        visit[idx]=true;
        answer+=mindist;
        cur=idx;
        dist[idx]=INF;
    }
    return answer;
}