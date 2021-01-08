#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    
    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int maxCnt=0;
    bool visit[101][101];
    memset(visit,false,sizeof(visit));
    queue<pair<int,int>> q;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visit[i][j]||picture[i][j]==0)continue;
            number_of_area++;
            int color = picture[i][j];
            visit[i][j]=true;
            q.push({i,j});
            int curCnt=0;
            while(!q.empty()){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                curCnt++;
                for(int k=0;k<4;k++){
                    int nr = dx[k]+r;
                    int nc = dy[k]+c;
                    if(nr>=0&&nr<m&&nc>=0&&nc<n){
                        if(picture[nr][nc]==color && !visit[nr][nc]){
                            visit[nr][nc]=true;
                            q.push({nr,nc});
                        }
                    }
                }
            }
            if(curCnt>max_size_of_one_area){
                max_size_of_one_area=curCnt;
            }
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
