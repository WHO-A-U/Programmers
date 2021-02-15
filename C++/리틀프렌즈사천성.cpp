#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

char map[101][101];
int rs,cs;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
bool isPossible(pair<int,int> cur){
    int r = cur.first;
    int c = cur.second;
    char target = map[r][c];
    
    bool visit[101][101];
    memset(visit,false,sizeof(visit));

    queue<pair< int,int> > q;
    q.push(cur);
    queue<pair<int,int>> tmp;
    for(int k=0;k<2;k++){  
        while(!q.empty()){
            int cr = q.front().first;
            int cc = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = cr+dx[i];
                int nc = cc+dy[i];
                while(nr>=0&&nr<rs&&nc>=0&&nc<cs){
                    if(!(nr==r&&nc==c)&&map[nr][nc]==target){
                        return true;
                    }
                    if(map[nr][nc]!='.'){
                        break;
                    }
                    visit[nr][nc]=true;
                    tmp.push({nr,nc});
                    nr+=dx[i];
                    nc+=dy[i];
                }   
            }      
        }
        q=tmp;
    }
    return false;
}
void mapErase(char c){
    for(int i=0;i<rs;i++){
        for(int j=0;j<cs;j++){
            if(map[i][j]==c){
                map[i][j]='.';
            }
        }
    }
}
string solution(int m, int n, vector<string> board) {
    rs = m;
    cs = n;
    pair<int,int> v['Z'-'A'+1];
    
    memset(map,0,sizeof(map));
    string answer = "";
               
    vector<char> node;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            map[i][j]=board[i][j];
            char cur = board[i][j];
            if('A'<=cur&&cur<='Z'){   
                node.push_back(cur);
                v[cur-'A']={i,j};
            }
        }
    }
    
    sort(node.begin(),node.end());
    node.erase(unique(node.begin(),node.end()),node.end());
    
    while(node.size()>0){
        bool flag=false;
        for(int i=0;i<node.size();i++){
            char cur =node[i];
            if(isPossible(v[cur-'A'])){
                mapErase(cur);
                answer+=cur;
                
                vector<char> tmp;
                for(int j=0;j<node.size();j++){
                    if(node[j]!=cur){
                        tmp.push_back(node[j]);
                    }
                }
                node = tmp;
                flag=true;
                break;
            }
            
        }
        if(!flag){
            answer = "IMPOSSIBLE";
            break;
        }
    }
                                
    return answer;
}