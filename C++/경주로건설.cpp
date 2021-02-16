#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <iostream>
#define INF 0x3f3f3f3f;
using namespace std;
int d[26][26][2];
//0세로 길   1 가로 길
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int solution(vector < vector < int > > board) {
    int answer = 0;
    int n = board.size();

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            d[i][j][0]=d[i][j][1]=INF;
        }
    }

    d[0][0][0]=0;
    d[0][0][1]=0;

    queue<pair<pair<int,int>,int>> q;
    q.push({{0,0},0});
    q.push({{0,0},2});

    while(!q.empty()){
        int cr = q.front().first.first;
        int cc = q.front().first.second;
        int dir = q.front().second;
        int cost = d[cr][cc][dir/2];
        q.pop();
        for(int i=0;i<4;i++){
            int nr = cr+dx[i];
            int nc = cc+dy[i];
            if(nr>=0&&nr<n&&nc>=0&&nc<n){
                int ext = dir/2==i/2?100:600;
                if(board[nr][nc]!=1 && cost+ext<d[nr][nc][i/2]){
                    d[nr][nc][i/2]=cost+ext;
                    q.push({{nr,nc},i});
                }
            }
        }
    }

    return min(d[n-1][n-1][0],d[n-1][n-1][1]);
}