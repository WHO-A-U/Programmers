import java.util.*;
class Solution {
    public int solution(int[] arr) {
        int answer = 1;
        int []p = new int[101];
        Arrays.fill(p,0);
        for(int i=0;i<arr.length;i++){
            int cur = arr[i];
            int []c = new int[101];
            Arrays.fill(c,0);
            for(int j=2;j<100;j++){
                while(cur%j==0){
                    c[j]++;
                    cur/=j;
                }
            }
            
            for(int j=0;j<101;j++){
                p[j] = Math.max(p[j],c[j]);
            }
        }
        for(int i=0;i<101;i++){
            for(int j=0;j<p[i];j++){
                answer*=i;
            }
        }
        return answer;
    }
}