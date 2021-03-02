#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int r=arr1.size(),c=arr2[0].size(),n=arr2.size();
    for(int i=0;i<r;i++){
        vector<int> newRow;
        for(int j=0;j<c;j++){
            int arc=0;
            for(int k=0;k<n;k++){
                arc+=(arr1[i][k]*arr2[k][j]);
            }
            newRow.push_back(arc);
        }
        answer.push_back(newRow);
    }
    return answer;
}