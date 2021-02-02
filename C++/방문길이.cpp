#include <string>
#include<cstring>
#include <algorithm>
#include <iostream>
using namespace std;
bool d[11][11][2];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int convert(char c){
    switch(c){
        case 'U':
            return 0;
        case 'D':
            return 1;
        case 'R':
            return 2;
        case 'L':
            return 3;
        default:
            return -1;
    }
}
int solution(string dirs) {
    int answer = 0,cr = 5,cc=5;
    memset(d,false,sizeof(d));
    int nr,nc;
    for(int i=0;i<dirs.length();i++){
        int k=convert(dirs[i]);
        nr = cr+dx[k];
        nc = cc+dy[k];
        if(nr>=0&&nr<=10&&nc>=0&&nc<=10){
            int dr = min(cr,nr);
            int dc = min(cc,nc);
            d[dr][dc][k/2]=true;
            cr = nr;
            cc = nc;
        }
    }
    for(int i=0;i<11;i++){
        for(int j=0;j<11;j++){
            for(int k=0;k<2;k++){
                if(d[i][j][k]){
                    answer++;
                }
            }
        }
    }
    return answer;
}