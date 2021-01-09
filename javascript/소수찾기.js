let arr ;
let visit;
function go (str,tmp,cnt){
    let ans=0;
    if(cnt===0){
        if(arr[parseInt(tmp)]===true){
            arr[parseInt(tmp)]=false;
            return 1;
        }
        else{
            return 0;
        }
    }
    for(let i=0;i<str.length;i++){
        if(visit[i]===false){
            visit[i]=true;
            ans+=go(str,tmp+str[i],cnt-1);
            visit[i]=false;
        }
    }
    return ans;
}
function solution(numbers) {
    const limit = Math.pow(10,numbers.length);
    visit=Array.from({length:numbers.length},()=>false);
    arr=Array(limit);
    arr[1]=false;
    arr[2]=true;
    for(let i=3;i<limit;i++){
        if(arr[i]===false){
            continue;
        }
        let flag =true;
        for(let j=2;j*j<=i;j++){
            if(i%j===0){
                flag=false;
                break;
            }
        }
        if(flag){
            arr[i]=true;
            for(let j=i*2;j<limit;j+=i){
                arr[j]=false;
            }
        }
        else{
            arr[i]=false;
        }
    }
    let ans=0;
    for(let i=1;i<=numbers.length;i++){
        ans+=go(numbers,"",i);
    }
    return ans;
}