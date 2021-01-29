#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

int getTimestamp(int h , int m , int s){
    return h*60*60+m*60+s;
}
string getHours(int ts){
    int h = ts/3600;
    string str = to_string(h);
    if(str.length()<2)str="0"+str;
    return str;
}
string getMinutes(int ts){
    int h = ts/3600;
    int m = (ts-h*3600)/60;
    string str = to_string(m);
    if(str.length()<2)str="0"+str;
    return str;
}
string getSeconds(int ts){
    int s = ts%60;
    string str = to_string(s);
    if(str.length()<2)str="0"+str;
    return str;
}
long long t[100*60*60+60*60+60];
string solution(string play_time, string adv_time, vector<string> logs) {
    memset(t,0,sizeof(t));
    for (const string &log : logs){
        int h1 , h2 , m1 , m2 , s1 , s2;
        sscanf(log.c_str(),"%d:%d:%d-%d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
        t[getTimestamp(h1,m1,s1)]+=1;
        t[getTimestamp(h2,m2,s2)]-=1;
    }
    int h1 , h2 , m1 , m2 , s1 , s2;
    sscanf(play_time.c_str(),"%d:%d:%d",&h1,&m1,&s1);
    sscanf(adv_time.c_str(),"%d:%d:%d",&h2,&m2,&s2);

    int MAXTIME = getTimestamp(h1,m1,s1);
    int TAKETIME = getTimestamp(h2,m2,s2);

    int cur=0;
    for(int i=0;i<=MAXTIME;i++){
        cur+=t[i];
        t[i]=cur;
    }
    for(int i=1;i<=MAXTIME;i++){
        t[i]+=t[i-1];
    }
    long long maxTakeTime=0;
    int ans=0;
    for(int i=0;i+TAKETIME<=MAXTIME;i++){
        if(i==0){
            if(maxTakeTime<t[i-1+TAKETIME]){
                ans=i;
                maxTakeTime=t[i-1+TAKETIME];
            }
        }
        else{
            if(maxTakeTime<t[i-1+TAKETIME]-t[i-1]){
                ans=i;
                maxTakeTime=t[i-1+TAKETIME]-t[i-1];
            }
        }
    }
    return getHours(ans)+":"+getMinutes(ans)+":"+getSeconds(ans);
}