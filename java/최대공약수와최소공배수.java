class Solution {
    
    public int gcd(int a, int b){
        while(true){
            int n = a%b;
            if(n==0)return b;
            a = b;
            b = n;
        }
    }
    public int[] solution(int n, int m) {
        return new int[]{gcd(n,m),n*m/(gcd(n,m))};
    }
}