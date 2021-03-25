class Solution {
    public int solution(int n) {
        int answer = 0;
        boolean[] prime = new boolean[1000001];
        for(int i=1;i<prime.length;i++){
            prime[i]=true;
        }
        prime[1]=false;
        
        for(int i=2;i<prime.length;i++){
            if(!prime[i])continue;
            for(int j=i*2;j<prime.length;j+=i){
                prime[j]=false;
            }
        }
        
        for(int i=2;i<=n;i++){
            if(prime[i]){
                answer++;
            }
        }
        
        return answer;
    }
}