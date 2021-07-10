#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
using vpii = vector<pii>;
vector<int> people;
vi e[10001];
vi edir[10001];
bool chk[10001];
int cnt=0,root;
void go(int idx){
    chk[idx]=true;
    for(int next : e[idx]){
        if(!chk[next]){
            edir[idx].push_back(next);
            go(next);
        }
    }
}
pii getGroupCount(int idx,int maxCnt){
    // first : 개별의 갯수 , second : 군집의 갯수
    pii tmp = {people[idx],0};
    chk[idx]=true;

    vpii childs;
    for(auto next : edir[idx]){
        if(!chk[next]){
            childs.push_back(getGroupCount(next,maxCnt));
        }
    }

    sort(childs.begin(),childs.end());

    for(auto child: childs){
        if(tmp.first + child.first <= maxCnt){
            tmp.first += child.first;
        }else{
            tmp.second += 1;
        }
        tmp.second += child.second;
    }
    return tmp;
}
int solution(int k, vector<int> num, vector<vector<int>> links) {

    memset(chk,false,sizeof(chk));
    int n = num.size(),minVal=0,sum=0;
    people=num;

    for(int i=0;i<n;i++){
        sum+=num[i];
        minVal = max(minVal,num[i]);
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            int from  = i;
            int to  = links[i][j];
            if(to!=-1){
                e[from].push_back(to);
                e[to].push_back(from);
            }
        }
    }

    go(0);

    int l=minVal,r=sum,mid,ans=INF;
    while(l<=r){
        memset(chk,false,sizeof(chk));
        mid=(l+r)/2;
        auto result = getGroupCount(0,mid);
        int need = (result.first > 0 ? result.second+1 : result.second);
        if( k >= need){
            ans = min(ans , mid);
            r = mid-1;
        }else if(k<need){
            l = mid+1;
        }
    }
    return ans;
}