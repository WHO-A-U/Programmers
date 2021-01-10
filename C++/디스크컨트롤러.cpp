#include <string>
#include <vector>
#include<queue>
#include<algorithm>
#include<iostream>

using namespace std;
bool cmp (vector<int> &a,vector<int> &b){
    if(a[0]<b[0])return true;
    return false;
}

struct pqcmp{
    bool operator()(const vector<int> &a , const vector<int> &b){
        if(a[1]>b[1])return true;
        return false;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0,time=0,completeJobs=0,idx=0;
    priority_queue < vector<int> , vector<vector<int>> , pqcmp > pq;
    sort(jobs.begin(),jobs.end(),cmp); 
    vector<int> p ;
    p.push_back(-1);
    while(completeJobs!=jobs.size()){
        while(idx<jobs.size()&&jobs[idx][0]==time)pq.push(jobs[idx++]);
        time++;
        if(idx<jobs.size()&&p[0]==-1&&pq.size()==0)continue;
        if(p[0]==-1){
            p = pq.top();
            pq.pop();
        }
        p[1]--;
        if(p[1]==0){
            answer+=(time-p[0]);
            completeJobs++;
            p[0]=-1;
        }
    }
    return answer/jobs.size();
}