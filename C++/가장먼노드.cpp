#include <string>
#include <vector>
#include<algorithm>
#include<queue>
using namespace std;
int visit[20001];
vector<int> node[20001];
int solution(int n, vector<vector<int>> edge) {
    int answer = 0,maxCnt=0;;
    for(int i=0;i<edge.size();i++){
        node[edge[i][0]].push_back(edge[i][1]);
        node[edge[i][1]].push_back(edge[i][0]);
    }
    for(int i=1;i<=n;i++){
        visit[i]=-1;
    }
    queue<int> q;
    q.push(1);
    visit[1]=0;
    while(!q.empty()){
        int cur = q.front();
        int curCnt = visit[cur];
        q.pop();
        for(int i=0;i<node[cur].size();i++){
            int next = node[cur][i];
            if(visit[next]==-1||curCnt+1<visit[next]){
                visit[next]=curCnt+1;
                maxCnt = max(maxCnt,visit[next]);
                q.push(next);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(visit[i]==maxCnt)answer++;
    }
    return answer;
}