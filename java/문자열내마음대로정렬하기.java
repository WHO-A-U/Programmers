// import java.util.*;

// class Solution {
//   public String[] solution(String[] strings, int n) {
//       List<String> list = Arrays.asList(strings);
//       list.sort((a, b) -> {
//           if(a.charAt(n)==b.charAt(n)){
//               return a.compareTo(b);
//           }
//           return a.charAt(n)-b.charAt(n);
//       });
//       return list.toArray(new String[0]);
//   }
// }
import java.util.*;
class Solution {
    public String[] solution(String[] strings, int n) {
        String[] answer = strings;
        for(int i=0;i<strings.length;i++){
            for(int j=0;j<strings.length-(i+1);j++){
                if(comp(answer[j],answer[j+1],n)){
                    swap(answer,j,j+1);
                }
            }
        }
        return answer;
    }
    
    public boolean comp(String a , String b,int n){
        if(a.charAt(n)==b.charAt(n)){
            return b.compareTo(a)<0;
        }
        return b.charAt(n)-a.charAt(n)<0;
    }
    
    public void swap(String[] arr , int a , int b){
        String tmp = arr[a];
        arr[a]=arr[b];
        arr[b]=tmp;
    }
}




