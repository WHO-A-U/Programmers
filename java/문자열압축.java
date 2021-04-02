class Solution {
    public static int getLen(int size , String s){
        int ret=0;
        int cnt=0;
        String tmp="";
        for(int i=0;i+size<=s.length();i+=size){
            String cur = s.substring(i, i+size);
            if(tmp.equals(cur)){
                cnt++;
            }else{
                ret+=(tmp.length());
                if(cnt>1){
                    ret+=Integer.toString(cnt).length();
                }
                tmp = cur;
                cnt=1;
            }
        }
        ret+=(tmp.length());
        if(cnt>1){
            ret+=Integer.toString(cnt).length();
        }
        ret+=(s.length()%size);
        return ret;
    }
    public int solution(String s) {
        int len = s.length();
        int answer = len;
        for(int i=1;i<=len/2+1;i++){
            answer = Math.min(answer , getLen(i,s));
        }
        return answer;
    }
}