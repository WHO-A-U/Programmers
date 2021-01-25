#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

bool d[20][33];
int menu[33];
bool v[33];
vector<char> menus;
vector<char> selected;
vector<string> ans;
vector<string> tmp;
int maxVal;
int excute(){
    if(selected.size()==0)return 0;
    int a = menu[selected[0]-'A'];
    for(int i=1;i<selected.size();i++){
        a&=menu[selected[i]-'A'];
    }
    int cnt=0;
    while(a!=0){
        if(a%2==1)cnt++;
        a/=2;
    }
    return cnt>1?cnt:0;
}
string getSelectedMenu (){
    string a ="";
    for(int i=0;i<selected.size();i++){
        a+=selected[i];
    }
    return a;
}
void go(int cnt,int cur){
    if(cnt==0){
        int val = excute();
        if(val>0){
            if(val>maxVal){
                tmp.clear();
                maxVal=val;
                tmp.push_back(getSelectedMenu());
            }else if(val==maxVal){
                tmp.push_back(getSelectedMenu());
            }
        }
        return ;
    }
    if(cur==menus.size())return ;

    selected.push_back(menus[cur]);
    
    go(cnt-1,cur+1);
    selected.pop_back();
    go(cnt,cur+1);
    return ;
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    memset(v,false,sizeof(v));
    memset(d,0,sizeof(d));
    memset(menu,0,sizeof(menu));
    int n = orders.size();
    maxVal=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<orders[i].size();j++){
            v[orders[i][j]-'A']=true;
            d[i][orders[i][j]-'A']=true;
        }
    }
    for(int i=0;i<='Z'-'A';i++){
        if(v[i]){
            menus.push_back((char)('A'+i));
        }

    }

    for(int i=0;i<menus.size();i++){
        int c=0;
        for(int j=0;j<n;j++)if(d[j][menus[i]-'A'])c|=(1<<j);
        menu[menus[i]-'A']=c;
    }

    for(int i=0;i<course.size();i++){
        maxVal=0;
        tmp.clear();
        memset(v,false,sizeof(v));
        go(course[i],0);
        for(int j=0;j<tmp.size();j++){
            answer.push_back(tmp[j]);
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}