class Solution {
    public boolean solution(int x) {
        int m = 0,a=x;
        while(a!=0){
            m+=(a%10);
            a/=10;
        }
        return x%m==0?true:false;
    }
}