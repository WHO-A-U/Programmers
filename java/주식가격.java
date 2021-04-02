import java.util.*;
class Solution {
    Stack<pair> stack = new Stack<>();
    public class pair{
        public int a,b;
        pair(int a, int b){
            this.a = a;
            this.b = b;
        }
    }
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        
        for(int i=0;i<prices.length;i++){
            while(!stack.empty()&&stack.peek().b>prices[i]){
                answer[stack.peek().a]=i-stack.peek().a;
                stack.pop();
            }
            stack.push(new pair(i,prices[i]));
        }
        while(!stack.empty()){
                answer[stack.peek().a]=prices.length-stack.peek().a-1;
                stack.pop();
        }
        return answer;
    }
}