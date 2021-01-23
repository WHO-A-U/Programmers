#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

bool d[103][103][2];
int N;

bool verifySim(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(d[i][j][0]){if(i>0){if(!((j==0&&d[i][j][1]) || (j>0&&(d[i][j][1]||d[i][j-1][1]))||d[i-1][j][0]))return false;}}
            if(d[i][j][1]){if(!((i>0 && (d[i-1][j][0] || d[i-1][j+1][0])) || (j>0 && d[i][j-1][1]&&d[i][j+1][1]))){return false;}}
        }
    }
    return true;
}
void Add(int r,int c,int which){// which 0 기둥 1 보

    d[r][c][which]=true;
    if(verifySim())return ;
    d[r][c][which]=false;

}
void Delete(int r,int c,int which){// which 0 기둥 1 보

    d[r][c][which]=false;
    if(verifySim())return ;
    d[r][c][which]=true;
}
void excuteInst(int r,int c,int which,int menu){
    if(menu==1){//설치
        Add(r,c,which);
    }else{//삭제
        Delete(r,c,which);
    }
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    N=n;
    memset(d,false,sizeof(d));
    vector<vector<int>> answer;
    for(int i=0;i<build_frame.size();i++){
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int which = build_frame[i][2]; //0 기둥 1 보
        int menu = build_frame[i][3]; //0 삭제 1 설치
        excuteInst(y,x,which,menu);
    }

    for(int j=0;j<=N+1;j++){
        for(int i=0;i<=N+1;i++){
             for(int k=0;k<2;k++){
                if(d[i][j][k]){
                    vector<int> tmp ;
                    tmp.push_back(j);
                    tmp.push_back(i);
                    tmp.push_back(k);
                    answer.push_back(tmp);
                }
            }
        }
    }
    return answer;
}