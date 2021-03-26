class Solution {
    public int solution(int num) {
        int i=1;
        long a = num;
        if(a==1)return 0;
        while(i<=500){
            if(a%2==0)
                a/=2;
            else
                a = a*3+1;
            if(a==1)break;
            i++;
        }
        return (i>500)?-1:i;
    }
}