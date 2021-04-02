class Solution {
    public String solution(int a, int b) {
        int []month  ={0,31,29,31,30,31,30,31,31,30,31,30,31};
        String[] Days={"FRI","SAT","SUN","MON","TUE","WED","THU"};
        int cnt=0;
        for(int i=1;i<a;i++){
            cnt+=month[i];
        }
        cnt+=b;
        cnt--;
        cnt%=7;
        return Days[cnt];
    }
}
