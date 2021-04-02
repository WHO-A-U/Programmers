import java.util.*;
class Solution {
    
    class ComStr implements Comparator<String>{
        public int compare(String a, String b){
            String A = a+b;
            String B = b+a;
            return Integer.parseInt(B)-Integer.parseInt(A);
        }
    }
    
    public String solution(int[] numbers) {
        String answer = "";
        
        int cnt=0;
        for(int i=0;i<numbers.length;i++){
            if(numbers[i]==0){
                cnt++;
            }
        }
        if(cnt==numbers.length){
            return "0";
        }
        
        String []num = new String[numbers.length];
        for(int i=0;i<numbers.length;i++){
            num[i] = String.valueOf(numbers[i]);
        }
        Arrays.sort(num,new ComStr() );
        for(int i=0;i<numbers.length;i++){
            answer+=num[i];
        }
        return answer;
    }
}