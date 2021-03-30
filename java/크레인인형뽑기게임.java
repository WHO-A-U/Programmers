import java.util.*;
class Solution {
    public int answer;
    public Stack<Integer> stack;
    public int getDoll(int[][]board,int col){
        int ret=-1;
        for(int i=0;i<board.length;i++){
            if(board[i][col]>0){
                ret=board[i][col];
                board[i][col]=0;
                break;
            }
        }
        return ret;
    }
    public void pushDoll(int doll){
        if(stack.empty()){
            stack.push(doll);
        }else{
            if((int)stack.peek()==doll){
                stack.pop();
                answer+=2;
            }else{
                stack.push(doll);
            }
        }
    }
    public int solution(int[][] board, int[] moves) {
        answer=0;
        stack = new Stack<Integer>();
        for(int i=0;i<moves.length;i++){
            int doll = getDoll(board,moves[i]-1);
            if(doll!=-1){
                pushDoll(doll);
            }
        }
        return answer;
    }
}