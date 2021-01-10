function solution(brown, yellow) {
    const add = parseInt((brown+4)/2);
    for(let i=1;i<=parseInt(add/2);i++){
        if(i*(add-i)==brown+yellow){
            return [add-i,i];
        }
    }   
}
console.log(solution(10,2));