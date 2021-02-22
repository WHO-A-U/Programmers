#include <string>
#include <vector>
#include <map>
#include<algorithm>
#include <cstring>
#include<iostream>
#define INF 0x3f3f3f3f3f3f
using namespace std;
map<long long,int> m;
vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for(int i=0;i<room_number.size();i++){
        long long cur = room_number[i];
        auto p = m.lower_bound(cur);
        long long idx = p->first;
        int cnt = p->second;
        long long head = (idx==0||cnt==0)?INF:idx-cnt+1;
        
        if(head<=cur){
            cur = idx+1;
        }
        
        answer.push_back(cur);
        p = m.lower_bound(cur);
        idx = p->first;
        cnt = p->second;
        
        head = (idx==0||cnt==0)?INF:idx-cnt+1;
        
        if(m.find(cur-1)!=m.end()){
            m[cur]=m[cur-1]+1;
            m.erase(cur-1);
        }else{
            m[cur]++;
        }
        if(head-cur==1){
            m[idx]+=m[cur];
            m.erase(cur);
        }
        
        
        cout<<"new record : \n";
        for(auto i=m.begin();i!=m.end();i++){
            cout<<i->first<<" "<<i->second<<"\n";
        }
    }
    return answer;
}