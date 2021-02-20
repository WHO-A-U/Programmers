#include <string>
#include <vector>

using namespace std;
    
vector<int> solution(string s) {
    vector<int> answer(2,0);
    while(s!="1"){
        int cnt=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0')
                answer[1]++;
            else
                cnt++;
        }
        string tmp="";
        while(cnt>0){
            tmp = (cnt%2==1?"1":"0")+tmp;
            cnt/=2;
        }
        s=tmp;
        answer[0]++;
    }
    return answer;
}