#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
#define MAX 40001
using namespace std;
bool p[MAX];
vector<int> prime;
vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for(int i=0;i<MAX;i++)p[i]=true;

    p[1]=false;

    for(int i=2;i<MAX;i++){
        if(!p[i])continue;
        for(int j=i*i;j<MAX;j+=i){
            p[j]=false;
        }
    }

    for(int i=2;i<MAX;i++){
        if(p[i]){
            prime.push_back(i);
        }
    }

    int n=prime.size();

    for(long long i=begin;i<=end;i++){
        if(i==1){
            answer.push_back(0);
            continue;
        }
        int temp=1;
        for(int j=0;j<n;j++){
            if(prime[j]*prime[j]>i)break;
            if((i%prime[j]==0)&&(i/prime[j]!=1)&&(i/prime[j]<=10000000)){
                temp = i/prime[j];
                break;
            }
        }
        for(int j=2; j*j<=i; j++){
           if(j>5000)break;
            if(i%j==0){
                if(i/j<=10000000){
                    temp = max(temp,(int)i/j);
                    break;   
                }
            }
         }
        answer.push_back(temp);
    }

    return answer;
}