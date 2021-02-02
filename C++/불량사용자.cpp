#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;

map<string,int> m;
vector<int> v[9];
bool visit[9];
set <string> s;
vector<int> tmp;
int ans,n;
bool cmpId (string from,string a){
    if(a.length()!=from.length())return false;
    for(int i=0;i<a.length();i++){
        if(from[i]!='*'){
            if(from[i]!=a[i]){
                return false;
            }
        }
    }
    return true;
}
void go(int cnt){
    
    if(cnt==n){
        vector<int> t=tmp;
        sort(t.begin(),t.end());
        string str="";
        for(int i=0;i<t.size();i++){
            str+=to_string(t[i]);
        }
        s.insert(str);
        return ;
    }
    for(int i=0;i<v[cnt].size();i++){
        if(!visit[v[cnt][i]]){
            visit[v[cnt][i]]=true;
            tmp.push_back(v[cnt][i]);
            go(cnt+1);
            visit[v[cnt][i]]=false;
            tmp.pop_back();
        }
    }
    return ;
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int idx=0;
    ans=0;
    n=banned_id.size();
    memset(visit,false,sizeof(visit));
    for(int i=0;i<user_id.size();i++){
        m.insert({user_id[i],idx++});
    }
    for(int i=0;i<banned_id.size();i++){
        for(int j=0;j<user_id.size();j++){
            if(cmpId(banned_id[i],user_id[j])){
                v[i].push_back(m[user_id[j]]);
            }
        }
    }
    
    go(0);
    return s.size();
}