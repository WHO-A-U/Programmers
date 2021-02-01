#include <string>
#include <vector>
#include<cstring>
using namespace std;

long long d[10001];
int solution(int n) {
    int answer = 0;
    for(int i=0;i<10001;i++){
        d[i]=i;
    }
    for(int i=1;i<10001;i++){
        d[i]+=d[i-1];
    }
    for(int i=n;i>=0;i--){
        for(int j=i-1;j>=0;j--){
            if(d[i]-d[j]==n){
                answer++;
                break;
            }
            if(d[i]-d[j]>n)
                break;
        }
    }
    return answer;
}