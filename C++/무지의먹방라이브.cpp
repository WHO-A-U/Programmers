#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
vector<pair<int,int>> foodList; //{cost , idx}
queue<pair<int,int>> q;
bool food[200001];
int solution(vector<int> food_times, long long k) {
    int answer = 0;
    int n = food_times.size();
    int foodN = n;
    long long entireTime=0;
    memset(food,false,sizeof(food));
    
    for(int i=1;i<=n;i++){
        entireTime+=food_times[i-1];
        foodList.push_back({food_times[i-1],i});
    }
    if(entireTime<=k)return -1;
    sort(foodList.begin(),foodList.end());
    
    for(int i=0;i<foodList.size();i++){
        q.push(foodList[i]);
    }
    int curTime=0;
    while(!q.empty()){
        int nextTime = q.front().first;
        long long diff = (long long)(nextTime-curTime)*n;
        if(diff<k){
            k-=diff;
            while(!q.empty()&&q.front().first==nextTime){
                food[q.front().second]=true;
                q.pop();
                n--;
            }
            curTime = nextTime;
        }else{
            k%=n;
            for(int i=1;i<=foodN;i++){
                if(!food[i]){
                    if(k==0){
                        return i;
                    }else{
                        k--;
                    }
                }
            }
        }
        
    }
    
    return -1;
}