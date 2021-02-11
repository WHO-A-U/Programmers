#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
long long calNum(long long a, long long b,char c){
    if(c=='+')return a+b;
    if(c=='-')return a-b;
    if(c=='*')return a*b;
}
long long solution(string expression) {
    long long answer = 0,num=0;
    vector<long long> nums;
    vector<char> opers,p;
    for(int i=0;i<expression.length();i++){
        if(expression[i]=='*'||expression[i]=='+'||expression[i]=='-'){
          nums.push_back(num);
            opers.push_back(expression[i]);
            num=0;
        }else{
            num*=10;
            num+=expression[i]-'0';
        }
    }
    nums.push_back(num);
    p=opers;
    sort(p.begin(),p.end());
    p.erase(unique(p.begin(),p.end()),p.end());
    do{
        vector<long long> ans=nums,tmp;
        tmp.push_back(nums[0]);
        vector<char> op(opers),optmp;
        for(int i=0;i<p.size();i++){
            for(int j=0;j<op.size();j++){
               
                if(op[j]==p[i]){
                    tmp.back() = calNum(tmp.back(),ans[j+1],op[j]);
                }
                else{
                    optmp.push_back(op[j]);
                    tmp.push_back(ans[j+1]);
                }
           } 
            op=optmp;
            ans=tmp;
            optmp.clear();
            tmp.clear();
            tmp.push_back(abs(ans[0]));
        }
        answer = max(answer , tmp[0]);
    }while(next_permutation(p.begin(),p.end()));
    
    return answer;
}