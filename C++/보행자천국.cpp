#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int MOD = 20170805;

int rMax[501];
int cMax[501];
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    memset(rMax,0,sizeof(rMax));
    memset(cMax,0,sizeof(cMax));

    rMax[0]=cMax[0]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0&&j==0)continue;
            if(city_map[i][j]==0)answer=rMax[i]=cMax[j]=(rMax[i]+cMax[j])%MOD;
            if(city_map[i][j]==1)rMax[i]=cMax[j]=0;
        }
    }
    return answer;
}