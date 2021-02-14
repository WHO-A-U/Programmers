#include <vector>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
#define INF 0x3f3f3f
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int d[101][201];
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    vector<int> e[201];
    int answer = 0;
    for(int i=0;i<101;i++){
        for(int j=0;j<201;j++){
            d[i][j]=INF;
        }
    }
    for(int i=1;i<=n;i++){
        e[i].push_back(i);
    }
    
    for(int i=0;i<edge_list.size();i++){
        int a = edge_list[i][0];
        int b = edge_list[i][1];
        
        e[a].push_back(b);
        e[b].push_back(a);
    }

    queue<int> q;
    
    int start = gps_log.front();
    int end = gps_log.back();
    int T = gps_log.size();
    d[1][start]=0;

    for(int i=1;i<T;i++){
        int curTime = i;
        for(int j=1;j<=n;j++){
            if(d[i][j]!=INF){
                q.push(j);
            }
        }

        while(!q.empty()){
            
            int curNode = q.front();
            int curCost = d[curTime][curNode];
            q.pop();
            
            for(int j=0;j<e[curNode].size();j++){

                int nextNode = e[curNode][j];

                int diff = gps_log[curTime]!=nextNode ? 1 : 0;
                
                d[curTime+1][nextNode] = min(d[curTime+1][nextNode] , curCost+diff);
            }
        }
    }
    return d[T][end]==INF?-1:d[T][end];
}