function getSum(list){
    return list.reduce((acc,x)=>acc+=x[1],0);
}
function solution(genres, plays) {
    let map={},idx=0,arr=[],answer=[];
    for(let i in genres){
        if(genres[i] in map){
            let key = map[genres[i]];
            arr[key].push([parseInt(i),plays[i]]);
        }
        else{
            arr[idx]=[[parseInt(i),plays[i]]];
            map[genres[i]]=idx++;
        }
    }
    arr.sort((x,y)=>getSum(y)-getSum(x));
    for(let i of arr){
        i.sort((x,y)=>y[1]-x[1]);
        for(let j in i){
            if(j>=2)break;
            answer.push(i[j][0]);
        }
    }
    return answer;
}