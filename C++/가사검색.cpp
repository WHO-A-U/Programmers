#include <string>
#include <vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

struct Trie{
    Trie *go[26];
    bool output;
    int branch;
    int words;

    Trie():output(false),branch(0),words(0){fill(go,go+26,nullptr);}

    ~Trie(){
        for(int i=0;i<26;i++){
            if(go[i])
                delete go[i];
        }
    }

    void insert(char * str){
        if(*str=='\0'){
            words++;
        }else{
            if(!go[*str-'a']){
                branch++;
                go[*str-'a'] = new Trie;
            }
            words++;
            go[*str-'a']->insert(str+1);
        }
    }
    
    int find(char * str){
        if(*str == '\0'){
            return words;
        }else{
            if(go[*str-'a']){
                return go[*str-'a']->find(str+1);
            }else{
                return 0;
            }
        }
    }
};
string getQuery(string s,bool isBack){
    string ret="";
    int n = s.length();
    if(isBack){
        for(int i=n-1;i>=0;i--){
            if(s[i]=='?')
                break;
            ret+=s[i];
        }
    }else{
        for(int i=0;i<n;i++){
            if(s[i]=='?')
                break;
            ret+=s[i];
        }
    }
    return ret;
}
Trie* front[10001];
Trie* back[10001];
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    for(int i=1;i<=10000;i++){
        front[i] = new Trie();
        back[i] = new Trie();
    }
    for(string s: words){
        int len = s.length();
        vector<char> t(s.begin(),s.end());
        vector<char> b=t;
        t.push_back('\0');
        front[len]->insert(&t[0]);
        
        reverse(b.begin(),b.end());
        b.push_back('\0');
        back[len]->insert(&b[0]);
    }
    
    for(string q:queries){
        int len = q.length();
        bool isBack=false;
        if(q[0]=='?'){
            isBack=true;
        }
        string query = getQuery(q,isBack);
        // cout<<query<<"\n";
        vector<char> qv(query.begin(),query.end());
        // if(qv.size()==1){
        //     answer.push_back(words.size());
        //     continue;
        // }
        qv.push_back('\0');
        if(isBack){
            answer.push_back(back[len]->find(&qv[0]));
        }else{
            answer.push_back(front[len]->find(&qv[0]));
        }
        
    }
    return answer;
}