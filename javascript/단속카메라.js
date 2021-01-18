function solution(routes) {
    var answer = 0;
    routes.sort((x,y)=>x[0]===y[0]?x[1]-y[1]:x[0]-y[0]);
    console.log(routes);
    let i=0,l=undefined,r;
    while(routes.length>0){
        if(l===undefined){
            l=routes[i][0],r=routes[i][1];
            routes.shift();
        }
        else{
            if(!(routes[i][0]>r||routes[i][1]<l)){//끊기
                l=Math.max(routes[i][0],l),r=Math.min(routes[i][1],r);
                routes.shift();
            }else{
                answer++;
                l=undefined;
            }
        }
    }
    if(l!==undefined)answer++;
    return answer;
}