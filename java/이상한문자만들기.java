class Solution {
    public String solution(String s) {
        String answer = "";
        int cnt=0;
        for(int i=0;i<s.length();i++){
            char ch = s.charAt(i);
            if(cnt%2==0){
                ch = Character.toUpperCase(ch);
            }
            if(cnt%2==1){
                ch = Character.toLowerCase(ch);
            }
            cnt++;
            if(ch==' ')cnt=0;
            answer+=ch;
        }
        return answer;
    }
}