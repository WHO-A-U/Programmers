#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
map<string,int> m;
vector<int> solution(vector<string> gems) {
    vector<int> answer(2,1);
    int from=1,maxCnt=0;
    for(int i=1;i<=gems.size();i++){
        string cur = gems[i-1];
        if(m.find(cur)==m.end()){
            m[cur]=1;
        }else{
            m[cur]++;
        }
        while(m[gems[from-1]]>1){
            m[gems[from-1]]--;
            from++;
        }
        if(maxCnt<m.size()){
            maxCnt = m.size();
            answer[0]=from;
            answer[1]=i;
        }
        else{
            if(maxCnt==m.size()){
                if(i-from<answer[1]-answer[0]){
                    answer[0]=from;
                    answer[1]=i;
                }
            }
        }
    }
    return answer;
}