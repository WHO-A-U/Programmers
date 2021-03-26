import java.util.*;
class Solution {
    public int[] solution(int[] answers) {
        
        int [] score = {0,0,0};
        int[][] d = {{1,2,3,4,5,1,2,3,4,5},{2,1,2,3,2,4,2,5},{3,3,1,1,2,2,4,4,5,5}};
        int []idx={0,0,0};
        
        for(int i=0;i<answers.length;i++){
            for(int j=0;j<3;j++){
                if(answers[i]==d[j][idx[j]]){
                    score[j]++;
                }
                idx[j] = (idx[j]+1)%(d[j].length);
            }
        }
        int maxVal=0;
        for(int i=0;i<3;i++){
            maxVal=Math.max(maxVal , score[i]);
        }
        ArrayList<Integer> v = new ArrayList<Integer>();
        for(int i=0;i<3;i++){
            if(maxVal==score[i]){
                v.add(i+1);
            }
        }
        int [] answer = new int[v.size()];
        for(int i=0;i<v.size();i++){
            answer[i] = v.get(i);
        }
        
        return answer;
    }
}