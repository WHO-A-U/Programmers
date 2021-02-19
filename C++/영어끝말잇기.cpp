#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
set <string> s;
vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2,0);
    string word=words[0];
    int player = 0;
    bool flag=true;
    int i=1;
    s.insert(word);
    for(;i<words.size();i++){
        player = (player +1)%n;
        if(s.find(words[i])!=s.end()||word[word.length()-1]!=words[i][0]){
            flag=false;
            break;
        }
        s.insert(words[i]);
        word = words[i];
    }
    if(!flag){
        answer[0]=player+1;
        answer[1]=i/n+1;
    }
    return answer;
}