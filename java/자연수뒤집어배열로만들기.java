import java.util.*;
class Solution {
    public int[] solution(long n) {
        ArrayList<Integer> arr = new ArrayList<Integer>();
        while(n!=0){
            arr.add((int)(n%10L));
            n/=10;
        }
        int[] answer = new int[arr.size()];
        for(int i=0;i<arr.size();i++){
            answer[i] = arr.get(i);
        }
        
        return answer;
    }
}