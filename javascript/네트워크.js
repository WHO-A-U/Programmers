function solution(n, computers) {//n 컴퓨터 개수 , computers relation matirx
    var answer = 0;
    for(let i=0;i<n;i++)computers[i][i]=0;
    let v = Array(n).fill(false);
    for(let i=0;i<n;i++){
        if(v[i]===true)continue;
        answer++;
        v[i]=true;
        go(i);
    }

    function go(idx){
        for(let i=0;i<n;i++){
            if(computers[idx][i]===1&&v[i]===false){
                v[i]=true;
                go(i);
            }
        }
    }
    return answer;
}