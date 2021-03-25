class Solution {
    public String solution(String s, int n) {
        String answer = "";
        for(int i=0;i<s.length();i++){
            char c = s.charAt(i);
            if(c>='a'&&c<='z'){
                c = (char)((c+n-'a')%('z'-'a'+1)+'a');
            }else if(c>='A'&&c<='Z'){
                c = (char)((c+n-'A')%('z'-'a'+1)+'A');
            }
            answer+=c;
        }
        return answer;
    }
}