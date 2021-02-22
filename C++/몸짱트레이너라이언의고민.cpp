#include <bits/stdc++.h>
#define INF 0x3f3f3f
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int t[1400];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool go(int r , int c , vector<vector<int>> map,int mid,int cnt){
    if(cnt==1){
        return true;
    }
    vector<vector<int>> tmp=map;
    int n = tmp.size();
    tmp[r][c]=0;
    queue<pair<int,int>> q;
    q.push({r,c});
    while(!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second;
        int dist = tmp[cr][cc];
        q.pop();
        for(int i=0;i<4;i++){
            int nr = cr+dx[i];
            int nc = cc+dy[i];
            if(nr>=0&&nr<n&&nc>=0&&nc<n){
                if(tmp[nr][nc]>dist+1){
                    tmp[nr][nc]=dist+1;
                    q.push({nr,nc});
                }
            }
        }
    }
    int count=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(tmp[i][j]>=mid){
                count--;
                if(go(i,j,tmp,mid,cnt-1))
                    return true;
            }
            if(count<=0)break;
        }
        if(count<=0)break;
    }
    return false;
}
bool isPossible(int n,int mid , int cnt){
    for(int i=0;i<n/2;i++){
        vector<vector<int>> map(n,vector<int> (n,INF));
        if(go(0,i,map,mid,cnt))return true;
    }
    return false;
}
int solution(int n, int m, vector<vector<int>> timetable) {
    int answer = 0;
    memset(t,0,sizeof(t));
    for(auto x : timetable){
        t[x.front()]++;
        t[x.back()+1]--;
    }
    int cnt=0,maxCnt=0;
    for(int i=600;i<=1320;i++){
        cnt+=t[i];
        maxCnt = max(maxCnt,cnt);
    }
    cout<<maxCnt;
    int l=1,r=(n-1)*2,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(isPossible(n,mid,maxCnt)){
            answer = max(answer,mid);
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return maxCnt==1?0:answer;
}