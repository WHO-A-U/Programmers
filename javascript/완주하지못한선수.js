function solution(participant, completion) {
    var o = {};
    for(let i of participant){
        if(i in o)
            o[i]+=1;
        else
            o[i]=1;
    }
    for(let i of completion){
        if(i in o)
            o[i]-=1;
    }
    for(let i in o){
        if(o[i]>0)return i
    }
}