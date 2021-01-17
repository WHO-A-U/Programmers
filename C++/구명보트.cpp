#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end());
    int l=0,r=people.size()-1;
    while(l<=r){
        if(people[l]+people[r]<=limit){
            answer++;
            l++;
            r--;
        }else{
            answer++;
            r--;
        }
    }
    return answer;
}
int main(){
    priority_queue<int,vector<int> ,greater<int>> pq;
    pq.push(1);
    pq.push(4);
    pq.push(3);
    pq.push(8);
    pq.push(6);
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }

}