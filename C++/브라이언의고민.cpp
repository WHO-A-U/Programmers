#include <string>
#include<vector>
#include<cstring>
#include<iostream>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> v['z'-'a'+1];
vector<int> lower;

string s;

int rule['z'-'a'+1];
int idx['z'-'a'+1];
bool p[1002];
bool isLowerCase(char cur){
    if('a'<=cur&&cur<='z')return true;
    return false;
}

bool isCorrectRule2(int vidx){
    int fr = v[vidx][0]+1, bk = v[vidx][1]-1;
    if(isLowerCase(s[fr])||isLowerCase(s[bk]))return false;
    bool isrule2Only=true;
    char bet;
    for(int i=fr;i<=bk;i++){
        if(isLowerCase(s[i])){
            bet=s[i];
            isrule2Only=false;
            break;
        }
    }

    if(isrule2Only)return true;
    
    for(int i=fr;i<=bk;i++){
        if((i-fr)%2==0){//대문자가 나와야됨
            
            if(isLowerCase(s[i])){
                cout<<"%";
                return false;
            }
        }
        else{//똑같은 소문자가 나와야됨
            if(s[i]!=bet){
                cout<<"&";
                return false;
            }
                
        }
    }
    return true;

    
}
bool isCorrect(){
    for(int i=0;i<'z'-'a'+1;i++){
        if(v[i].size()==0)continue;
        // if(v[i].size()==1){ //AaA
        //     if(v[i][0]-1>=0&&(v[i][0]+1<s.length())&&(!isLowerCase(s[v[i][0]-1]))&&!isLowerCase(s[v[i][0]+1])){
        //         rule[i]=1;
        //         if(p[v[i][0]-1]||p[v[i][0]+1])return false;
        //         p[v[i][0]-1]=p[v[i][0]+1]=true;
        //     }
        //     else{
        //         cout<<"1 /";
        //         cout<<i<<endl;
        //         return false;
        //     }
        // }
        // else 
        if(v[i].size()==2){  //aAVCDESa
            if(v[i][1]-v[i][0]==2){//aCa
                if(v[i][0]-1<0||v[i][1]+1>=s.length()||isLowerCase(s[v[i][0]-1])||isLowerCase(s[v[i][1]+1]))
                    rule[i]=2;
                else
                    rule[i]=1;
            }
            else{
                if(!isCorrectRule2(i)){
                    cout<<"2 /";
                    cout<<i<<endl;
                    return false;
                }
                rule[i]=2;
            }
        }
        else{
            for(int j=1;j<v[i].size();j++){
                if(v[i][j]-v[i][j-1]!=2){
                    cout<<"3 /";
                    cout<<i<<endl;
                    return false;
                }
            }
            rule[i]=1;
        }

        // for(int i=0;i<s.length();i++){
        //     if(p[i]){
        //         cout<<"!"<<" ";
        //     }else{
        //         cout<<"0 ";
        //     }
        // }
        cout<<"\n";
        if(rule[i]==1){
            cout<<"@";
            for(int j=0;j<v[i].size();j++){
                if(v[i][j]-1<0||v[i][j]+1>=s.length()){
                    cout<<"##";
                    return false;
                }
                if(p[v[i][j]-1]||p[v[i][j]+1]||isLowerCase(s[v[i][j]-1])||isLowerCase(s[v[i][j]+1])){
                    cout<<"!"<<i<<" "<<j;
                    cout<<p[v[i][j]-1] <<" "<< p[v[i][j]+1] <<" "<<s[v[i][j]-1] <<" "<<s[v[i][j]+1];
                    cout<<"!!!!";
                    return false;
                }
            }
            for(int j=0;j<v[i].size();j++){
                cout<<"paste : "<<s[v[i][j]-1]<<" "<<s[v[i][j]+1]<<'\n';
                p[v[i][j]-1]=p[v[i][j]+1]=true;
            }
        }else{//rule2 일경우
            if(isLowerCase(s[v[i][0]+1])||isLowerCase(s[v[i][1]-1])){
                cout<<"&&";
                return false;
            }
                    
        }
    }
    return true;
}
string cuts(int start , int end){
    string ret="";
    for(int i=start;i<=end&&i<s.length();i++){
        if(!isLowerCase(s[i]))
            ret+=s[i];
    }
    return ret;
}
string solution(string sentence) {
    s=sentence;
    string answer = "";
    memset(idx,0,sizeof(idx));
    memset(p,false,sizeof(p));
    memset(rule,false,sizeof(rule));

    for(int i=0;i<'z'-'a'+1;i++){
        v[i].clear();
    }
    bool rule1=false,rule2=false,inWord=false;
    // char rule1Char = NULL;
    int prevCharIdx=-1;
    int wordStartIdx=-1;
    for(int i=0;i<sentence.size();i++){
        const char cur = sentence[i];
        if(isLowerCase(cur)){
            v[cur-'a'].push_back(i);
            lower.push_back(i);
        }
    }
    if(!isCorrect()){
        return "invalid";
    }
    
    // int i=0;
    // while(i<lower.size()){
    //     int curIdx = lower[i];
    //     char curChar = sentence[curIdx];
        
    // }
    int start=0;
    int i=0;
    vector<string> ans;
    while(i<s.length()){
        // cout<<i<<"\n";
        if(i+1<s.length()&&isLowerCase(s[i+1]) &&rule[s[i+1]-'a']==1){
            if(start<=i-1)
                ans.push_back(cuts(start,i-1));
            ans.push_back(cuts(v[s[i+1]-'a'][0]-1,v[s[i+1]-'a'][v[s[i+1]-'a'].size()-1]+1));
            start=i=v[s[i+1]-'a'][v[s[i+1]-'a'].size()-1]+2;
            continue;
        }
        if(isLowerCase(s[i])&&rule[s[i]-'a']==2){
            if(start<=i-1)
                ans.push_back(cuts(start,i-1));
            ans.push_back(cuts(v[s[i]-'a'][0],v[s[i]-'a'][1]));
            start=i=v[s[i]-'a'][1]+1;
            continue;
        }
        // if(!isLowerCase(s[i])){
        i++;
        // }
        // if(i>11)break;
    }
    if(start<i)ans.push_back(cuts(start,i));
    for(int i=0;i<ans.size()-1;i++){
        answer+=(ans[i]+" ");
    }
    answer+=ans[ans.size()-1];
    return answer;
    // return answer;
}
int main(){
    vector<string> testcase; 
    testcase.push_back("HaEaLaLaObWORLDb"); //HELLO WORLD 
    testcase.push_back("SpIpGpOpNpGJqOqA"); //SIGONG JOA 
    testcase.push_back("A"); //A 
    testcase.push_back("HELLOWORLD"); //HELLOWORLD 
    testcase.push_back("aHbEbLbLbOacWdOdRdLdDc"); //HELLO WORLD 
    testcase.push_back("HaEaLaLObWORLDb"); //HELL O WORLD 
    testcase.push_back("AAA"); //AAA 
    testcase.push_back("aHELLOWORLDa"); //HELLOWORLD 
    testcase.push_back("AAAaBaAbBBBBbCcBdBdBdBcCeBfBeGgGGjGjGRvRvRvRvRvR"); //AA ABA BBBB C BBBB C BB GG GGG RRRRRR 
    testcase.push_back("aIaAM"); //I AM 
    testcase.push_back("bAaOb"); //AO 
    testcase.push_back("AxAxAxAoBoBoB"); //invalid 
    testcase.push_back("a"); //invalid 
    testcase.push_back("Aa"); //invalid 
    testcase.push_back("aA"); //invalid 
    testcase.push_back("HaEaLaLaOWaOaRaLaD"); //invalid 
    testcase.push_back("abHELLObaWORLD"); //invalid 
    testcase.push_back("aHELLOa bWORLDb"); //invalid 
    testcase.push_back("TxTxTxbAb"); //invalid 
    testcase.push_back("bTxTxTaTxTbkABaCDk"); //invalid 
    testcase.push_back("baHELLOabWORLD"); //invalid 
    testcase.push_back("AxAxAxABcBcBcB"); //AAAA BBBB 
    testcase.push_back("A B"); //invalid 
    testcase.push_back("oBBoA"); //BB A 
    testcase.push_back("AxAxAxA"); //AAAA 
    testcase.push_back("HaEaLaLaObWORLDbSpIpGpOpNpGJqOqAdGcWcFcDdeGfWfLeoBBoAAAAxAxAxAA"); //HELLO WORLD SIGONG J O A GWFD GWL BB AAA AAAA A 
    testcase.push_back("aBcAadDeEdvAvlElmEEEEm"); //BA DE A E EEEE 
    testcase.push_back("AcAcABaBaB"); //A A AB B B 
    testcase.push_back("aGbWbFbDakGnWnLk"); //GWFD GWL 
    testcase.push_back("aCaCa"); //invalid 
    for (int i = 0; i < testcase.size(); ++i) { 
        cout << '[' << solution(testcase[i]) << ']' << '\n'; 
    } return 0;

}