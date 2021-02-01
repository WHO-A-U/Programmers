#include <string>
#include <vector>
#include <cstring>
#include<iostream>
using namespace std;
int d[50001];
long long solution(int n, vector<int> works) {
    long long answer = 0;
    memset(d,0,sizeof(d));
    for(int i=0;i<works.size();i++){
        d[works[i]]++;
    }
    for(int i=50001;i>=1;i--){
        if(n>0&&d[i]>0){
            if(d[i]<=n){
                d[i-1]+=d[i];
                n-=d[i];
                d[i]=0;
            }else{
                d[i-1]+=(n);
                d[i]-=n;
                n=0;
            }
        }
    }
    for(int i=1;i<50001;i++){
        int s = d[i];
        answer+=((long long)i*i*s);
    }
    return answer;
}