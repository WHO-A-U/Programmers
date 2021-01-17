function solution(clothes) {
    var answer = {};
    for(let i in clothes){
        if(i in answer){
            answer[i]=1;
        }else{
            answer[i]++;
        }
    }
    answer = Object.keys().map(x=>answer[x]+1).reduce((a,b)=>a+=b,0)-1;
    return answer;
}