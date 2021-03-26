import java.util.*;
class Solution {
    public long solution(long n) {
        long answer = 0;
        ArrayList<Integer> v = new ArrayList<Integer>();
        while(n!=0){
            v.add((int)(n%10));
            n/=10;
        }
        Collections.sort(v);
        for(int i=v.size()-1;i>=0;i--){
            answer*=10;
            answer+=(long)v.get(i);
        }
        return answer;
    }
}