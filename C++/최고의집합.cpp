#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int d = s/n;
    if(d==0){
        answer.push_back(-1);
    }else{
        int m = d!=1?s%n:s-d*n;
        for(int i=1;i<=n;i++){
            if(m>0){
                m--;
                answer.push_back(d+1);
            }else{
                answer.push_back(d);
            }
        }
    }
    sort(answer.begin(),answer.end());
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
    return answer;
}