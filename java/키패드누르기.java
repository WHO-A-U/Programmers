class Solution {
    public void move(int []s , int[] t){
        s[0]=t[0];
        s[1]=t[1];
    }
    public int getDist(int []s,int[] t){
        return Math.abs(s[0]-t[0])+Math.abs(s[1]-t[1]);
    }
    public String solution(int[] numbers, String hand) {
        String answer = "";
        int[][] digit={{3,1},{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
        int[]l = {3,0};
        int[]r = {3,2};
        for(int i=0;i<numbers.length;i++){
            char ch=' ';
            if(numbers[i]%3==2||numbers[i]==0){
                int ld = getDist(l,digit[numbers[i]]);
                int rd = getDist(r,digit[numbers[i]]);
                if(ld==rd){
                    if(hand.equals("right")){
                        ch='R';
                        move(r,digit[numbers[i]]);
                    }else{
                        ch='L';
                        move(l,digit[numbers[i]]);
                    }
                }else{
                    if(ld<rd){
                        ch='L';
                        move(l,digit[numbers[i]]);
                    }else{
                        ch='R';
                        move(r,digit[numbers[i]]);
                    }
                }
            }
            else if(numbers[i]%3==1){
                ch = 'L';
                move(l,digit[numbers[i]]);
            }else if(numbers[i]%3==0){
                ch = 'R';
                move(r,digit[numbers[i]]);
            }
            answer+=ch;
        }
        return answer;
    }
}