#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
int d[12];
int answer;
void go(int cnt,int n){
    if(cnt==n){
        answer++;
    }
    for(int i=0;i<n;i++){
        if(d[i]>=0)continue;
        bool flag=true;
        for(int j=0;j<cnt;j++){
            int dist = cnt-j;
            int r = i+dist;
            int l = i-dist;
            if((l>=0&&d[l]==j)||(r<n&&d[r]==j))flag=false;   
        }
        if(flag){
                d[i]=cnt;
                go(cnt+1,n);
                d[i]=-1;
        }
    }
}
int solution(int n) {
    memset(d,-1,sizeof(d));
    answer = 0;
    go(0,n);
    return answer;
}