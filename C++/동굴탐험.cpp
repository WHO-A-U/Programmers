#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> edge[200001];
vector<int> tree[200001];
bool chk[200001];
bool isLocked[200001];
map<int,int> lock;
bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;

    memset(chk,false,sizeof(chk));
    memset(isLocked,false,sizeof(isLocked));

    for(auto p : path){
        edge[p[0]].push_back(p[1]);
        edge[p[1]].push_back(p[0]);
    }
    
    for(auto o : order){
        isLocked[o[1]]=true;
        lock.insert({o[0],o[1]});
    }
    
    queue<int> q;
    q.push(0);
    chk[0]=true;

    while(!q.empty()){
        int cur =  q.front();
        q.pop();
        for(int next : edge[cur]){
            if(!chk[next]){
                tree[cur].push_back(next);
                q.push(next);
                chk[next]=true;
            }
        }
    }
    
    memset(chk,false,sizeof(chk));

    if(isLocked[0])
        return false;
    
    chk[0]=true;
    q.push(0);
    int cnt=0;
    while(!q.empty()){
        cnt++;
        int cur = q.front();
        q.pop();
        if(lock.find(cur)!=lock.end()){
            int locked_num = lock[cur];
            isLocked[locked_num]=false;
            if(chk[locked_num]){
                q.push(locked_num);
            }
            lock.erase(cur);
        }
        for(int next : tree[cur]){
            if(!chk[next]){
                if(!isLocked[next]){
                    q.push(next);
                }
                chk[next]=true;
            }
        }
    }
    
    return cnt==n;
}