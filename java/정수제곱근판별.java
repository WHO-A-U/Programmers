class Solution {
    public long solution(long n) {
        long answer = -1;
        if(n==1L){
            return 4;
        }
        for(Long i=2L;i*i<=n;i++){
            if(i*i==n){
                answer = (i+1)*(i+1);
                break;
            }
        }
        return answer;
    }
}