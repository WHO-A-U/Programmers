const Lan ={
    "-":0,
    "java":1,
    "cpp":2,
    "python":3,
}
const dep ={
    "-":0,
    "backend":1,
    "frontend":2
}
const car ={
    "-":0,
    "junior":1,
    "senior":2,
}
const food={
    "-":0,
    "chicken":1,
    "pizza":2,
}

function solution(info, query) {
    var answer = [];
    const Q ={};
    function lower_count(arr,val){
        if(arr==undefined)return 0;
        let low = 0;
        let high = arr.length;
        let mid;
        while (low < high) {
            mid = low + Math.floor((high - low)/2);
            if (val <= arr[mid]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return arr.length-low;
    }

    let l=[0],d=[0],c=[0],f=[0];
    for(let i of info){
        let cur = i.split(" ");
        let score = parseInt(cur[4]);
        l.push(Lan[cur[0]]);
        d.push(dep[cur[1]]);
        c.push(car[cur[2]]);
        f.push(food[cur[3]]);
        for(let x of l){
            for (let y of d){
                for(let z of c){
                    for(let w of f){
                        let s = ""+x+y+z+w;
                        if(!(s in Q)){
                            Q[s]=[score];
                        }else{
                            Q[s].push(score);
                        }
                    }
                }
            }
        }
        l.pop();
        d.pop();
        c.pop();
        f.pop();
    }

    for(let i in Q){
        Q[i].sort((x,y)=>x-y);
    }
    
    for(let i of query){
        let cur = i.split(" ");
        let s = ""+Lan[cur[0]]+dep[cur[2]]+car[cur[4]]+food[cur[6]];
        answer.push(lower_count(Q[s],parseInt(cur[7])));
    }

    return answer;
}