function solution(citations) {
    var answer = 0;
    citations.sort((a,b)=>parseInt(a)-parseInt(b));
    for(let i=0;i<=10000;i++){
        if(citations.filter(x=>x>=i).length>=i)
            answer = Math.max(answer,i)
    }
    return answer;
}