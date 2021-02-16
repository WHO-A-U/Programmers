#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int ith=1;
    int sz = 2*w+1;
    for(int i=0;i<stations.size();i++){
        int l = stations[i]-w;
        if(ith<l){
            answer+=((l-ith-1)/sz)+1;
            ith=stations[i]+w+1;
        }else{
            ith=stations[i]+w+1;
        }
    }
    if(n>=ith){
        answer+=((n-ith)/sz)+1;
    }

    return answer;
}