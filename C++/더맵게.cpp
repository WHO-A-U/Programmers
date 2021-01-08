#include <string>
#include <vector>
#include <queue>

using namespace std;
int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int> > pq;
    for(int i=0;i<scoville.size();i++){
        pq.push(scoville[i]);
    }
    while(pq.size()>1){
        int a = pq.top();
        pq.pop();
        if(a>=K)return answer;
        int b = pq.top();
        pq.pop();
        answer++;
        pq.push(a+b*2);
    }
    if(!pq.empty()&&pq.top()<K)answer=-1;
    return answer;
}