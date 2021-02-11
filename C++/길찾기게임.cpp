#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

int d[100001][2];
vector<int> pre;
vector<int> post;
int parse(vector<pair<pair<int,int>,int>> cur){
    if(cur.size()==0){
        return -1;
    }
    vector<pair<pair<int,int>,int>> left,right;
    int maxH=-1,idx,xVal,num;
    for(int i=0;i<cur.size();i++){
        if(maxH<cur[i].first.second){
            maxH = cur[i].first.second;
            idx=i;
            num=cur[i].second;
            xVal=cur[i].first.first;
        }
    }
    for(int i=0;i<cur.size();i++){
        if(idx!=i){
            if(cur[i].first.first<xVal){
                left.push_back(cur[i]);
            }else{
                right.push_back(cur[i]);
            }
        }
    }
    int leftnum = parse(left);
    int rightnum = parse(right);
    d[num][0]=leftnum;
    d[num][1]=rightnum;
    return num;
}
void preorder(int num){

    pre.push_back(num);
    if(d[num][0]!=-1){
        preorder(d[num][0]);
    }
    if(d[num][1]!=-1){
        preorder(d[num][1]);
    }
    return ;
}
void postorder(int num){
    if(d[num][0]!=-1){
        postorder(d[num][0]);
    }
    if(d[num][1]!=-1){
        postorder(d[num][1]);
    }
    post.push_back(num);
    return ;
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<pair<pair<int,int>,int>> m;
    memset(d,-1,sizeof(d));
    for(int i=0;i<nodeinfo.size();i++){
        m.push_back({{nodeinfo[i][0],nodeinfo[i][1]},i+1});
    }
    int root = parse(m);
    preorder(root);
    postorder(root);
    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}