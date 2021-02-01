#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> d;
bool isPossible(int k,int val){
    int cnt=0;
    for(int i=0;i<d.size();i++){
        if(d[i]<val){
            cnt++;
        }else{
            cnt=0;
        }
        if(cnt>=k)
            return false;
    }
    return true;
}
int solution(vector<int> stones, int k) {
    int answer = 0;
    d=stones;
    long long l=0,r=200000000,mid;
    while(l<=r){
        mid = (l+r)/2;
        if(isPossible(k,(int)mid)){
            answer = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    return answer;
}