class Solution {
    public int[] solution(int[] arr) {
        int[] answer = new int[Math.max(arr.length-1,1)];
        int minVal = 10000000;
        for(int i=0;i<arr.length;i++){
            minVal = Math.min(minVal ,arr[i]);
        }
        for(int i=0,j=0;i<arr.length;i++){
            if(arr[i]!=minVal){
                answer[j++] = arr[i];
            }
        }
        if(arr.length==1){
            answer[0]=-1;
        }
        
        return answer;
    }
}