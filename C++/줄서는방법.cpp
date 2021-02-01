#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

long long d[21];
bool visit[21];
vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> tmp;
    memset(d,0,sizeof(d));
    memset(visit,false,sizeof(visit));
    d[0]=1;
    for(int i=1;i<n;i++){
        d[i]=d[i-1]*i;
    }
    for(int i=1;i<=n;i++){
        tmp.push_back(i);
    }
    for(int i=n;i>1;i--){
        long long c = (k-1)/d[i-1];
        visit[tmp[c]]=true;
        answer.push_back(tmp[c]);
        tmp.clear();
        for(int j=1;j<=n;j++){
            if(!visit[j]){
                tmp.push_back(j);
            }
        }
        k=((k-1)%d[i-1])+1;
    }
    answer.push_back(tmp[0]);
    return answer;
}