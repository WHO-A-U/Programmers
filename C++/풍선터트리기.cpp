#include <string>
#include <vector>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;
int minArr[1000001][2];
int solution(vector<int> a) {
    int answer=0;
    memset(minArr,0,sizeof(minArr));
    int minVal=INF,minIdx;
    for(int i=0;i<a.size();i++){
        if(minVal>a[i]) minVal=a[i];
        minArr[i][0]=minVal;
    }
    minVal=INF;
    for(int i=a.size()-1;i>=0;i--){
        if(minVal>a[i])minVal=a[i];
        minArr[i][1]=minVal;
    }
    for(int i=0;i<a.size();i++){
        if(!(minArr[i][0]<a[i]&&minArr[i][1]<a[i]))
           answer++;
    }
    return answer;
}