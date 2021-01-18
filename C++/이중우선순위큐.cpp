#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int getNum(string a){
    int ret=0;
    bool n=false;
    for(int i=0;i<a.length();i++){
        if(a[i]=='-')n=true;
        if(a[i]>='0'&&a[i]<='9'){
            ret=ret*10+(a[i]-'0');
        }
    }
    return (n?ret*-1:ret);
}
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue <int> pq_b;
    priority_queue <int,vector<int>,greater<int>> pq_s;
    int cnt=0,num=0;
    for(int i=0;i<operations.size();i++){
        if(operations[i][0]=='I'){
            num++;
            pq_b.push(getNum(operations[i]));
            pq_s.push(getNum(operations[i]));
        }else{
            if(num<=cnt)continue;
            cnt++;
            if(operations[i][2]=='1')pq_b.pop();
            else pq_s.pop();
        }
        if(num==cnt){
            while(!pq_b.empty())pq_b.pop();
            while(!pq_s.empty())pq_s.pop();
            cnt=0;
            num=0;
        }
    }
    if(pq_b.size()<=cnt){
        answer.push_back(0);
        answer.push_back(0);
    }else{
        answer.push_back(pq_b.top());
        answer.push_back(pq_s.top());
    }
    return answer;
}