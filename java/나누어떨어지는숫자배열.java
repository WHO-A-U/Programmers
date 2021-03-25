import java.util.*;
class Solution {
    public int[] solution(int[] arr, int divisor) {
        ArrayList<Integer> v = new ArrayList<Integer>();
        for(int i=0;i<arr.length;i++){
            if(arr[i]%divisor==0){
                v.add(arr[i]);
            }
        }
        int[] answer = new int[Math.max(1,v.size())];
        if(v.size()==0)answer[0]=-1;
        for(int i=0;i<v.size();i++){
           answer[i] = v.get(i);
        }
        Arrays.sort(answer);
        return answer;
    }
}