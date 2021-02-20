#include <string>
#include<cstring>
#include<algorithm>
#include <vector>
using namespace std;

int d[500001];
int last[500001];
int solution(vector<int> a) {
    int answer = 0;
    if(a.size()<2){
        return 0;
    }
    for(int i=0;i<500001;i++)
        last[i]=-1;
    memset(d,0,sizeof(d));
    int n= a.size();
    if(a[0]!=a[1]){
        d[a[0]]=1;
        last[a[0]]=1;
    }
    for(int i=1;i<n;i++){
        int cur = a[i];
        if(a[i-1]!=a[i]){
            if(last[a[i]]<i-1){
                last[a[i]]=i;
                d[a[i]]++;
            }
        }
        if(i+1<n){
         if(a[i]!=a[i+1]){
             if(last[a[i]]<i){
                 d[a[i]]++;
                 last[a[i]]=i+1;
             }
         }   
        }
    }
    for(int i=0;i<500001;i++){
        answer = max(answer,d[i]);
    }
    return answer*2;
}