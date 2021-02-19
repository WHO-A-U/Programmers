#include <vector>
#include <iostream>
#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 5001
using namespace std;

bool d[MAX];
vector<int> tmp,num,ans;
void go(int idx){
    if(tmp.size()==3){
        ans.push_back(tmp[0]+tmp[1]+tmp[2]);
        return ;
    }
    if(idx>=num.size())
        return ;
    tmp.push_back(num[idx]);
    go(idx+1);
    tmp.pop_back();
    go(idx+1);
    return ;
}
int solution(vector<int> nums) {
    int answer = 0;
    num=nums;
    for(int i=1;i<MAX;i++){
        d[i]=true;
    }
    d[2]=true;
    for(int i=3;i<MAX;i++){
        bool flag=true;
        if(!d[i])continue;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                flag=false;
                break;
            }
        }
        if(!flag){
            for(int j=i;j<MAX;j+=i){
                d[j]=false;
            }
        }else{
            for(int j=i*2;j<MAX;j+=i){
                d[j]=false;
            }
        }
    }
    go(0);
    for(int i=0;i<ans.size();i++){
        if(d[ans[i]]){
            answer++;
        }
    }
    return answer;
}