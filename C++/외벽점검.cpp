#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#define INF 0x3f3f3f
using namespace std;

vector<int> w ;
vector<int> d ;
int play(vector<int> rot , int n,int startIdx){
    int curIdx = startIdx;
    int targetNum = w.size();
    int curNum = 0;
    for(int i=0;i<rot.size();i++){
        int next = w[curIdx]+d[rot[i]];
        if(next>=n){
            next%=n;
            curNum+=(w.size()-1-curIdx);
            int tmp = 0;
            while(w[tmp]<=next){
                tmp++;
            }
            int nextIdx=tmp;
            curNum +=(nextIdx+1);
            curIdx = tmp;
        }else{
            if(next>=w[w.size()-1]){
                curNum +=(w.size()-curIdx);
                curIdx = 0;
            }else{
                int tmp = curIdx;
                while(w[tmp]<=next){
                    tmp++;
                }
                int nextIdx=tmp;
                curNum+=(nextIdx-curIdx);
                curIdx = tmp;
            }
        }
        if(curNum >= targetNum){
            return i+1;
        }
        
    }
    return INF;
}
int solution(int n, vector<int> weak, vector<int> dist) {
    w = weak;
    d = dist;
    int answer = INF;
    vector<int> rot;
    for(int i=0;i<dist.size();i++){
        rot.push_back(i);
    }
    do{
        for(int i=0;i<weak.size();i++){
            answer = min(answer , play(rot,n,i) );
        }

    }while(next_permutation(rot.begin(),rot.end()));
    return answer==INF?-1:answer;
}