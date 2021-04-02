import java.util.*;
class Solution {
    ArrayList<ArrayList<Integer>> e = new ArrayList<>();
    int []dist ;
    public int solution(int n, int[][] edge) {
        dist = new int[n];
        for(int i=0;i<n;i++){
            dist[i]=0x3f3f3f3f;
        }
        for(int i=0;i<n;i++){
            e.add(new ArrayList<Integer>());
        }
        for(int i=0;i<edge.length;i++){
            int a = edge[i][0]-1;
            int b = edge[i][1]-1;
            e.get(a).add(b);
            e.get(b).add(a);
        }
        
        Queue<Integer> q = new LinkedList<>();
        q.add(0);
        dist[0]=0;
        int maxVal=0;
        while(!q.isEmpty()){
            int cur = q.poll();
            int now = dist[cur];
            for(int i=0;i<e.get(cur).size();i++){
                int next = e.get(cur).get(i);
                if(dist[next]>now+1){
                    dist[next]=now+1;
                    maxVal = Math.max(dist[next],maxVal);
                    q.add(next);
                }
            }
        }
        
        
        int answer = 0;
        for(int i=0;i<n;i++){
            if(dist[i]==maxVal)
                answer++;
        }
        return answer;
    }
}