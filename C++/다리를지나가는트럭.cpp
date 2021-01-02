#include <string>
#include<cstring>
#include <vector>

using namespace std;

int d[10001];
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0,cnt=0,w=0,i=0;
    memset(d,0,sizeof(d));
 
    while(true){
        answer++;
        
        if(d[bridge_length]!=0){
            w-=d[bridge_length];
            cnt++;
        }
        
        for(int k=bridge_length;k>0;k--)
            d[k]=d[k-1];
        
        if(cnt>=truck_weights.size())
            break;
        
        if(i<truck_weights.size() && w+truck_weights[i]<=weight){
            w+=truck_weights[i];
            d[1]=truck_weights[i];
            i++;
        }
        
    }
    return answer;
}