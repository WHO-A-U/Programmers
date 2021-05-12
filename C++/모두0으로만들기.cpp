#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ft first
#define sd second
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vb = vector<bool>;
using vs = vector<string>;
using vd = vector<double>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vvi = vector<vi>;
using vvb = vector<vb>;
using vvll = vector<vll>;
using vvpii = vector<vpii>;
using vvpll = vector<vpll>;
using vvs = vector<vs>;
bool vv[300001];
vi e[300001];
vi d;

ll ans=0;
long long go(int cur){

    ll ret=d[cur],tmp;
    for(int next:e[cur]){
        if(!vv[next]){
            vv[next]=true;
            tmp=go(next);
            ret+=tmp;
            ans+=abs(tmp);
        }
    }
    return ret;
}
int j=0;
long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = 0;
    long long sum=0;
    for(int i : a)
        sum+=i;
    
    if(sum!=0)
        return -1;
    
    memset(vv,false,sizeof(vv));
    for(int i=0;i<edges.size();i++){
        int x = edges[i][0];
        int y = edges[i][1];
        e[x].push_back(y);
        e[y].push_back(x);
    }
    d=a;

    vv[0]=true;
    go(0);

    
    return ans;
}