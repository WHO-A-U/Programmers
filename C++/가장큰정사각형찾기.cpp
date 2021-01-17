#include <iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int d[1001][1001][3]; //0 value 1 row sum 2 col sum
int solution(vector<vector<int>> board)
{   
    int answer = 0,row=board.size(),col=board[0].size();
    memset(d,0,sizeof(d));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(board[i][j]==1){
                d[i][j][0]=d[i][j][1]=d[i][j][2]=1;
                if(i-1>=0)d[i][j][1]+=d[i-1][j][1];
                if(j-1>=0)d[i][j][2]+=d[i][j-1][2];
                if(i-1>=0&&j-1>=0){
                    int v = d[i-1][j-1][0]+1,r = d[i][j][1],c = d[i][j][2];
                    if(v>1&&r>1&&c>1){
                        d[i][j][0]=min(min(v,r),c);
                    }
                }
                answer = max(answer,d[i][j][0]*d[i][j][0]);
            }
        }
    }

    

    return answer;
}