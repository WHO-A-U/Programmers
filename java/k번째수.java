import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int len = commands.length;
        int[] answer = new int[len];
        for(int i=0;i<commands.length;i++){
            int l = commands[i][0]-1;
            int r = commands[i][1]-1;
            int th = commands[i][2]-1;
            int size = r-l+1;
            int[] arr = new int[size];
            for(int j=0;j<size;j++){
                arr[j] = array[j+l];
            }
            Arrays.sort(arr);
            answer[i] = arr[th];
        }
        return answer;
    }
}