#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int d[1000001][6];
int solution(vector<int> money) {
    int answer = 0;
    int n = money.size();
    memset(d,0,sizeof(d));
    d[0][1]=money[0];
    for(int i=1;i<n;i++){
        d[i][0]=max(d[i-1][1],d[i-1][0]);
        d[i][1]=d[i-1][0]+money[i];
    }
    d[n-1][3]=money[n-1];
    for(int i=n-2;i>=0;i--){
        d[i][2]=max(d[i+1][2],d[i+1][3]);
        d[i][3]=d[i+1][2]+money[i];
    }
    int ans=0;
    if(n>=1){
        d[1][5]=money[1];
        for(int i=2;i<n-1;i++){
            d[i][4]=max(d[i-1][4],d[i-1][5]);
            d[i][5]=d[i-1][4]+money[i];
        }
        ans = max(d[n-2][4],d[n-2][5]);
    }
    return max(ans,max(d[n-1][0],d[0][2]));
}