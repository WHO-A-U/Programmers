#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int d[101];
vector<int> e[101];
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    memset(d,0,sizeof(d));
    for(int i=0;i<results.size();i++){
        int a = results[i][0];
        int b = results[i][1];
        e[a].push_back(b);
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        bool visit[101];
        int cnt=0;
        memset(visit,false,sizeof(visit));
        visit[i]=true;
        q.push(i);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int j=0;j<e[cur].size();j++){
                int next = e[cur][j];
                if(!visit[next]){
                    visit[next]=true;
                    d[next]++;
                    q.push(next);
                    cnt++;
                }
            }
        }
        d[i]+=cnt;
    }
    for(int i=1;i<=n;i++){
       if(d[i]==n-1)answer++;
    }
    return answer;
}