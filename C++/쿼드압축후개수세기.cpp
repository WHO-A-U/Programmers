#include <string>
#include <vector>
using namespace std;
vector<vector<int>> d;
int dx[]={1,2,1,2};
int dy[]={1,1,2,2};
vector<int> go(int r,int c,int n){
    vector<int> tmp(2,0);
    if(n==1){
        tmp[d[r][c]]++;
        return tmp;
    }
    vector<int> v[4];
    v[0]=go(r,c,n/2);
    v[1]=go(r+n/2,c,n/2);
    v[2]=go(r,c+n/2,n/2);
    v[3]=go(r+n/2,c+n/2,n/2);
    for(int i=0;i<4;i++){
        for(int j=0;j<2;j++){
            tmp[j]+=v[i][j];
        }
    }
    if(tmp[0]==4&&tmp[1]==0)tmp[0]=1;
    if(tmp[0]==0&&tmp[1]==4)tmp[1]=1;
    return tmp;
}
vector<int> solution(vector<vector<int>> arr) {
    d=arr;
    return go(0,0,arr.size());
}