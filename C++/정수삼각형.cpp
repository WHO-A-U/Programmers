#include <string>
#include <vector>
#include<algorithm>
#include<cstring>
using namespace std;
int d[501][501];
vector<vector<int>> v;
int go(int r,int c){
    if(r>=v.size())return 0;
    if(d[r][c]!=-1)return d[r][c];
    return d[r][c]=max(go(r+1,c),go(r+1,c+1))+v[r][c];
}
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    memset(d,-1,sizeof(d));
    v=triangle;
    return go(0,0);
}