#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include<iostream>
#define INF 0x3f3f3f
using namespace std;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int landColor[301][301];
bool visit[301][301];
vector<int> node;
vector<pair<int,int>> l[90001];
int solution(vector<vector<int>> land, int height) {
    int answer = 0,landCnt=0,n = land.size();
    
    memset(visit,false,sizeof(visit));
    memset(landColor,0,sizeof(landColor));
    queue<pair<int,int>> q;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visit[i][j]){
                visit[i][j]=true;
                landColor[i][j]=landCnt;
                q.push({i,j});
                l[landCnt].push_back({i,j});
                while(!q.empty()){
                    int cr = q.front().first;
                    int cc = q.front().second;
                    int cur = land[cr][cc];
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nr = cr+dx[k];
                        int nc = cc+dy[k];
                        if(nr>=0&&nr<n&&nc>=0&&nc<n){
                            int diff = abs(land[nr][nc]-cur);
                            if(!visit[nr][nc]&&diff<=height){
                                visit[nr][nc]=true;
                                landColor[nr][nc]=landCnt;
                                q.push({nr,nc});
                                l[landCnt].push_back({nr,nc});
                            }
                        }
                    }
                }
                landCnt++;
            }
        }
    }

    vector<int> ans(landCnt,INF);
    vector<bool> v(landCnt,false);
    
    int next=0;
    v[0]=true;
    ans[0]=0;
    for(int i=0;i<landCnt-1;i++){
        for(int j=0;j<l[next].size();j++){
            int cr = l[next][j].first;
            int cc = l[next][j].second;
             for(int k=0;k<4;k++){
                int nr = cr+dx[k];
                int nc = cc+dy[k];
                if(nr>=0&&nr<n&&nc>=0&&nc<n){
                    int nColor = landColor[nr][nc];
                    if(!v[nColor]&&nColor!=next){
                        int diff = abs(land[nr][nc]-land[cr][cc]);
                        ans[nColor]=min(ans[nColor],diff);
                    }
                }
            }
        }
        int minVal = INF,idx;
         for(int j=0;j<landCnt;j++){
            if(!v[j]){
                if(minVal>ans[j]){
                    minVal = ans[j];
                    idx=j;
                }
            }
        }
        v[idx]=true;
        next = idx;
    }
    
    for(int i=0;i<landCnt;i++){
        answer+=ans[i];
    }
    
    
    return answer;
}