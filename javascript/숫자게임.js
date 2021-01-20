function solution(A, B) {
    var answer = 0,i=0,j=0;
    A.sort((a,b)=>a-b);
    B.sort((a,b)=>a-b);
    while(B.length>j){
        if(A[i]<B[j]){
            answer++;
            i++;
            j++;
        }
        else{
            j++;
        }
    }   
   return answer;
}