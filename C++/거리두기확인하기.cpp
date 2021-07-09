#include<bits/stdc++.h>
using namespace std;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool isValid(int r , int c){
    return r>=0&&r<5&&c>=0&&c<5;
}
int isSafe(vector<string> room){

    vector<pair<int,int>> people;

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(room[i][j]=='P'){
                people.push_back({i,j});
            }
        }
    }

    for(pair<int,int> person : people){
        bool chk[5][5];
        memset(chk,false,sizeof(chk));
        queue<pair<int,pair<int,int>>> q; 
        int sr = person.first;
        int sc = person.second;
        q.push({2,{sr,sc}});
        chk[sr][sc]=true;

        while(!q.empty()){
            int val = q.front().first;
            int cr = q.front().second.first;
            int cc = q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = cr+dx[i];
                int nc = cc+dy[i];
                if(isValid(nr,nc)&&!chk[nr][nc]&&val>0){
                    char next_seat = room[nr][nc];
                    if(next_seat!='X'){
                        if(next_seat=='P'){
                            return 0;
                        }
                        chk[nr][nc]=true;
                        q.push({val-1,{nr,nc}});
                    }
                }
            }
        }
    }
    return 1;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(auto room : places){
        answer.push_back(isSafe(room));
    }
    return answer;
}