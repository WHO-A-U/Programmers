#include <string>
#include <vector>
#include <cstring>
#include<queue>
#include<algorithm>
#include <iostream>

#define INF 987654321
using namespace std;

vector<pair<int,int>> card[7];
bool cardVisit[7];
vector<int> cardNumList;
vector<vector<int>> map;
int curRow,curCol,curVal,minVal;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

pair<int,int> getCtrlOper(int r,int c , int k){
    int nr = r+dx[k];
    int nc = c+dy[k];
    if(nr>=0&&nr<4&&nc>=0&&nc<4){
        while(1){
            if(map[nr][nc]!=0)
                break;
            if(nr+dx[k]>=0&&nr+dx[k]<4&&nc+dy[k]>=0&&nc+dy[k]<4){
                nr+=dx[k];
                nc+=dy[k];
            }
            else{
                break;
            }
        }
    }
    else{
        return {r,c};
    }
    
    return {nr,nc};
}
int bfs(int r1,int c1,int r2,int c2){
    int d[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            d[i][j]=INF;
        }
    }
    d[r1][c1]=0;
    queue<pair<int,int>> q;
    q.push({r1,c1});
    while(!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second;
        int cp = d[cr][cc];
        q.pop();
        for(int i=0;i<4;i++){
            int nr = cr+dx[i];
            int nc = cc+dy[i];
            if(nr>=0&&nr<4&&nc>=0&&nc<4){
                if(d[nr][nc]>cp+1){
                    d[nr][nc]=cp+1;
                    q.push({nr,nc});
                }
            }
        }
        for(int i=0;i<4;i++){
            pair<int,int> n = getCtrlOper(cr,cc,i);
            int nr = n.first;
            int nc = n.second;
            if(nr>=0&&nr<4&&nc>=0&&nc<4){
                if(d[nr][nc]>cp+1){
                    d[nr][nc]=cp+1;
                    q.push({nr,nc});
                }
            }
        }
    }
    return d[r2][c2];
}
int getVal(pair<int,int> s,pair<int,int> e){
    int val=0;
    val+=bfs(curRow,curCol,s.first,s.second);
    val+=bfs(s.first,s.second,e.first,e.second);
    map[s.first][s.second]=0;
    map[e.first][e.second]=0;
    curRow = e.first;
    curCol = e.second;
    return val;
}
void go(int cnt){
    if(cnt==0){
        minVal = min(minVal , curVal);
        return ;
    }
    for(int i=0;i<cardNumList.size();i++){
        int cardNumber = cardNumList[i];
        if(!cardVisit[cardNumber]){
            cardVisit[cardNumber]=true;
            
            int r =curRow;
            int c =curCol;
            int val = getVal(card[cardNumber][0],card[cardNumber][1]);
            curVal+=val;
            
            go(cnt-1);

            map[card[cardNumber][0].first][card[cardNumber][0].second]=cardNumber;
            map[card[cardNumber][1].first][card[cardNumber][1].second]=cardNumber;

            curRow = r;
            curCol = c;
            curVal-=val;
            val = getVal(card[cardNumber][1],card[cardNumber][0]);
            curVal+=val;
            go(cnt-1);

            map[card[cardNumber][0].first][card[cardNumber][0].second]=cardNumber;
            map[card[cardNumber][1].first][card[cardNumber][1].second]=cardNumber;

            curVal-=val;
            curRow = r;
            curCol = c;
            cardVisit[cardNumber]=false;
        }
    }
}
int solution(vector<vector<int>> board, int r, int c) {
    curRow=r,curCol=c,curVal=0,minVal=INF;
    map=board;
    memset(cardVisit,false,sizeof(cardVisit));
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(board[i][j]!=0){
                int n = board[i][j];
                cardVisit[n]=true;
                card[n].push_back({i,j});
            }
        }
    }
    for(int i=1;i<=6;i++){
        if(cardVisit[i]){
            cardNumList.push_back(i);
        }
    }
    memset(cardVisit,false,sizeof(cardVisit));

    int cardNum = cardNumList.size();

    go(cardNum);
    return minVal+(cardNum*2);
}