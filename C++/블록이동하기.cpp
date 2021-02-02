#include <string>
#include <vector>
#include<queue>
#include<algorithm>
#include<iostream>
#define INF 0x3f3f3f3f
using namespace std;
int d[101][101][2]; //0가로 1 세로
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
vector<vector<int>> b;
bool isPossible(int r, int c){
    if(r>=0&&r<b.size()&&c>=0&&c<b.size()&&b[r][c]!=1)return true;
    return false;
}
vector<pair<pair<int,int>,int>> getRowRotate (int cr[],int cc[]){
    vector<pair<pair<int,int>,int>> ret;
    
    int nr[2];
    int nc[2];
    for(int j=0;j<2;j++){
        nr[j]=cr[j]+dx[1];
        nc[j]=cc[j]+dy[1];
    }
    if(isPossible(nr[0],nc[0])&&isPossible(nr[1],nc[1])){
        ret.push_back({{cr[0],cc[0]},1});
        ret.push_back({{cr[1],cc[1]},1});
    }
    for(int j=0;j<2;j++){
        nr[j]=cr[j]+dx[3];
        nc[j]=cc[j]+dy[3];
    }
    if(isPossible(nr[0],nc[0])&&isPossible(nr[1],nc[1])){
        ret.push_back({{cr[0]-1,cc[0]},1});
        ret.push_back({{cr[1]-1,cc[1]},1});
    }
    return ret;
}
vector<pair<pair<int,int>,int>> getColRotate (int cr[],int cc[]){
    vector<pair<pair<int,int>,int>> ret;
    int nr[2];
    int nc[2];
    for(int j=0;j<2;j++){
        nr[j]=cr[j]+dx[0];
        nc[j]=cc[j]+dy[0];
    }
    if(isPossible(nr[0],nc[0])&&isPossible(nr[1],nc[1])){
        ret.push_back({{cr[0],cc[0]},0});
        ret.push_back({{cr[1],cc[1]},0});
    }
    for(int j=0;j<2;j++){
        nr[j]=cr[j]+dx[2];
        nc[j]=cc[j]+dy[2];
    }
    if(isPossible(nr[0],nc[0])&&isPossible(nr[1],nc[1])){
        ret.push_back({{cr[0],cc[0]-1},0});
        ret.push_back({{cr[1],cc[1]-1},0});
    }
    return ret;
}
void bfs(){
    int n = b.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<2;k++){
                d[i][j][k]=INF;
            }
        }
    }
    queue<pair<pair<int,int>,int>> q;
    d[0][0][0]=0;
    q.push({{0,0},0});
    while(!q.empty()){
        int dir = q.front().second;
        int cr[] = {q.front().first.first,q.front().first.first+dx[dir]};
        int cc[] = {q.front().first.second,q.front().first.second+dy[dir]};
        int cur = d[cr[0]][cc[0]][dir];
        q.pop();
        for(int i=0;i<4;i++){
            int nr[2];
            int nc[2];
            for(int j=0;j<2;j++){
                nr[j]=cr[j]+dx[i];
                nc[j]=cc[j]+dy[i];
            }
            if(isPossible(nr[0],nc[0])&&isPossible(nr[1],nc[1])){
                if(cur+1<d[nr[0]][nc[0]][dir]){
                    d[nr[0]][nc[0]][dir]=cur+1;
                    q.push({{nr[0],nc[0]},dir});
                }
            }
        }
        vector<pair<pair<int,int>,int>> tmp;
        if(dir==0){//현재 가로
            tmp = getRowRotate(cr,cc);    
        }else{//현재 세로
            tmp = getColRotate(cr,cc);
        }
        for(int i=0;i<tmp.size();i++){
            int nr = tmp[i].first.first;
            int nc = tmp[i].first.second;
            int ndir = tmp[i].second;
            if(d[nr][nc][ndir]>cur+1){
                d[nr][nc][ndir]=cur+1;
                q.push({{nr,nc},ndir});
            }
        }
        
    }
}

int solution(vector<vector<int>> board) {
    b=board;
    int answer = 0;
    int n=board.size();
    bfs();
    return min(d[n-1][n-2][0],d[n-2][n-1][1]);
}