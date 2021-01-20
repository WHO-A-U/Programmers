function solution(n, results) {
    var answer = 0;
    let e_in = Array(n+1);
    let e_out = Array(n+1);
    for(let i=0;i<n+1;i++){
        e_in[i]=new Array();
        e_out[i]=new Array();
    }
    let count = Array(n+1).fill(0);
    results.map(x=>{
        e_in[x[1]].push(x[0]);
        e_out[x[0]].push(x[1]);
    })
    for(let i=1;i<=n;i++){
        const visit=Array(101).fill(false);
        const arr=Array(101).fill(0);
        visit[i]=true;
        const queue=[i];
        while(queue.length>0){
            let cur = queue[0];
            queue.shift();
            for(let j=0;j<e_in[cur].length;j++){
                let next = e_in[cur][j];
                if(!visit[next]){
                    count[next]++;
                    queue.push(next);
                    visit[next]=true;
                }
            } 
        }
    }

    for(let i=1;i<=n;i++){
        const visit=Array(101).fill(false);
        const arr=Array(101).fill(0);
        visit[i]=true;
        const queue=[i];
        while(queue.length>0){
            let cur = queue[0];
            queue.shift();
            for(let j=0;j<e_out[cur].length;j++){
                let next = e_out[cur][j];
                if(!visit[next]){
                    count[next]++;
                    queue.push(next);
                    visit[next]=true;
                }
            } 
        }
    }
    return count.filter(x=>(x>0&&x===n-1)).length;
}