#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    vector<char> f = {'A','C','F','J','M','N','R','T'};
    do{
        bool possible=true;
        for(int i=0;i<data.size();i++){
            char a=data[i][0],b=data[i][2],op=data[i][3];
            int spc = data[i][4]-'0',x,y;
            for(int i=0;i<8;i++){
                if(f[i]==a)x=i;
                if(f[i]==b)y=i;
            }
            int dist = abs(x-y)-1;
            switch(op){
                case '=':
                    if(dist!=spc)possible=false;
                    break; ;
                case '>':
                    if(dist<=spc)possible=false;
                    break ;
                case '<':
                    if(dist>=spc)possible=false;
                    break ;       
            }
        }
        if(possible)answer++;
    }while(next_permutation(f.begin(),f.end()));
    return answer;
}