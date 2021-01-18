#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define INF 987654321
long long d[101][101];
bool v[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            d[i][j]=0;
        }
    }
    memset(v,false,sizeof(v));
    d[0][0]=1;
    for(int i=0;i<puddles.size();i++)
        v[puddles[i][1]-1][puddles[i][0]-1]=true; 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j])continue;
            if(i-1>=0&&!v[i-1][j])d[i][j]=(d[i-1][j]+d[i][j])%1000000007;
            if(j-1>=0&&!v[i][j-1])d[i][j]=(d[i][j-1]+d[i][j])%1000000007;
            
        }
    }
    return (d[n-1][m-1])%1000000007;
}