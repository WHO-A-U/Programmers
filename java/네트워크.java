import java.util.*;
class Solution {
    boolean visit[];
    int N;
    public int solution(int n, int[][] computers) {
        N=n;
        visit = new boolean[n];
        for(int i=0;i<n;i++){
            visit[i]=false;
        }
        int answer = 0;
        
        Queue<Integer> q = new LinkedList<Integer>();
        for(int i=0;i<n;i++){
            if(!visit[i]){
                answer++;
                q.add(i);
                while(!q.isEmpty()){
                    int cur = q.poll();
                    for(int j=0;j<n;j++){
                        if(computers[cur][j]==1 && !visit[j]){
                            visit[j]=true;
                            q.add(j);
                        }
                    }
                }
            }
        }
        
        return answer;
    }
}