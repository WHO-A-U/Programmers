#include <string>
#include <vector>

using namespace std;
int getOneBit(int a){
    int cnt=0;
    while(a!=0){
        if(a%2==1)cnt++;
        a/=2;
    }
    return cnt;
}
int solution(int n) {
    int b = getOneBit(n);
    for(int i=n+1;i<=1000000;i++){
        if(getOneBit(i)==b){
            return i;
        }
    }
}