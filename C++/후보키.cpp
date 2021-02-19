#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include<iostream>
#include<set>
using namespace std;
vector<int> tmp;
vector<vector<int>> ret;
vector<int>ans;
int colSize ;
void go(int idx,int cnt){
    if(cnt==tmp.size()){
        ret.push_back(tmp);
        return ;
    }
    if(idx>=colSize){
        return ;
    }
    tmp.push_back(idx);
    go(idx+1,cnt);
    tmp.pop_back();
    go(idx+1,cnt);
}
int solution(vector<vector<string>> relation) {
    int answer = 0;
    colSize = relation[0].size();
    for(int i=1;i<=colSize;i++){
        ret.clear();
        go(0,i);
        for(int j=0;j<ret.size();j++){
            bool flag=true;
            set<string> st;
            for(int k=0;k<relation.size();k++){
                string s = "";
                for(int z=0;z<ret[j].size();z++){
                    s+=relation[k][ret[j][z]];
                }
                if(st.find(s)!=st.end()){
                    flag=false;
                    break;
                }
                st.insert(s);
            }
            if(flag){
                int bm=0;
                for(int z=0;z<ret[j].size();z++){
                    bm=bm|(1<<ret[j][z]);
                }
                bool flag2=true;
                for(int z=0;z<ans.size();z++){
                    if((bm&ans[z])==ans[z]){
                        flag2=false;
                        break;
                    }
                }
                if(flag2){
                    ans.push_back(bm);
                }
            }
        }
        
    }
    return ans.size();
}