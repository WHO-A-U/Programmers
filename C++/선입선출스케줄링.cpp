#include <iostream>
#include <queue>
#include <vector>
#include<algorithm>
using namespace std;
using ll = long long;
int solution(int n, vector<int> cores) {
    int s = cores.size();
    if(n<=s)
        return n;
    
    int maxTime=-0x3f3f3f3f;
    int minTime=0x3f3f3f3f;
    
    for(int x : cores){
        if(maxTime<x)
            maxTime=x;
        if(minTime>x)
            minTime=x;
    }
    
    
    minTime = (minTime * (n - s)) / s;
    maxTime = (maxTime * (n - s)) / s;

    
    int l=minTime,r=maxTime,mid;
    int prev,cur,cnt;
    while(l<=r){
        mid = (l+r)/2;
      
        prev=s,cur=0;

        for(int x : cores){
            prev+=(mid/x);
            if(mid%x==0)
                cur++;
        }
        
        
        if(n>prev){
            l=mid+1;
        }
        else if(n<=(prev-cur)){
            r=mid-1;
        }
        else{
            cnt = prev-cur;
            for(int i=0;i<s;i++){
                if(mid%cores[i]==0)cnt++;
                if(cnt==n){
                    return i+1;
                    }
            }   
        }

    }
    return 0;
}