#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#define MOD 1000000007
using namespace std;
long long d[2501][3];
int solution(int n) {
    memset(d,0,sizeof(d));
    d[1][0]=3;
    d[1][1]=d[1][2]=1;
    for(int i=2;i<=n/2;i++){
        d[i][0] = (d[i-1][2]+d[i-1][1]+d[i-1][0]*3)%MOD;
        d[i][1] = (d[i-1][1]+d[i-1][0])%MOD;
        d[i][2] = (d[i-1][2]+d[i-1][0])%MOD;
    }
    return d[n/2][0];
}