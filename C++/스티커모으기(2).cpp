#include <iostream>
#include <vector>
#include<algorithm>
#include<cstring>
using namespace std;
int d[100001][2]; //d[i][0]고르지 않았을떄 d[i][1]골랐을때 최대값
int solution(vector<int> sticker)
{
    memset(d,0,sizeof(d));
    int answer=0,n = sticker.size();
    
    if(n==1)
        return sticker[0];
    
    d[0][1] = sticker[0];
    for(int i=1;i<n-1;i++){
        d[i][0] = max(d[i-1][0],d[i-1][1]);
        if(i-2>=0)
            d[i][1] = max(d[i-1][0],d[i-2][1])+sticker[i];
        else
            d[i][1] = d[i-1][0]+sticker[i];
    }
    
    answer = max(d[n-2][0],d[n-2][1]);

    memset(d,0,sizeof(d));
    for(int i=1;i<n;i++){
        d[i][0] = max(d[i-1][0],d[i-1][1]);
        if(i-2>=0)
            d[i][1] = max(d[i-1][0],d[i-2][1])+sticker[i];
         else
            d[i][1] = d[i-1][0]+sticker[i];
    }
    answer = max({answer,d[n-1][0],d[n-1][1]});
    return answer;
}