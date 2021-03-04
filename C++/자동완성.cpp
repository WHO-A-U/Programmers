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
            branch++;
            output = true;
        }else{
            if(!go[*str-'a']){
                branch++;
                go[*str-'a'] = new Trie;
            }
            words++;
            go[*str-'a']->insert(str+1);
        }
    }
    
    long long getAns(bool isRoot=false){
        long long result=0;
        if(isRoot || branch > 1) 
            result = words;
        else{
            if(branch==1&&words>1){
                result+=words;
            }
        }
        for(int i=0; i<26; i++)
            if(go[i]) result += go[i]->getAns();
        
        return result;
    }
};

int solution(vector<string> words) {
    Trie * root = new Trie;

    for(string s :words){
        
        vector<char> t(s.begin(),s.end());
        t.push_back('\0');
        
        root->insert(&t[0]);
        
    }
    return root->getAns(true);
}