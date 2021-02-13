#include <string>
#include <vector>
#include <cstring>
using namespace std;
int d[31];
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    memset(d,0,sizeof(d));
    for(int i=0;i<lost.size();i++){
        d[lost[i]]--;   
    }
    for(int i=0;i<reserve.size();i++){
        d[reserve[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(d[i]>0){
            if(i-1>=0&&d[i-1]<0){
                d[i-1]++;
            }
            else if(i+1<=n&&d[i+1]<0){
                d[i+1]++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(d[i]>=0)answer++;
    }
    return answer;
}