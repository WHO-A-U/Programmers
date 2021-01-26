function solution(new_id) {
    var answer = new_id.toLowerCase().split('').filter(x=>/[a-z0-9-_.]/.test(x)).reduce((acc,cur)=>acc+=(acc[acc.length-1]==' '&&cur=='.'?"":(cur==='.'?" ":cur))," ").trim().split('').map(x=>x===" "?".":x).join("");
    if(answer==="")answer="a";
    answer = answer.substr(0,15).split('').map(x=>x==="."?" ":x).join('').trim().split('').map(x=>x===" "?".":x).join('');
    if(answer.length<=2)
        answer=answer.split('').concat(Array(3-answer.length).fill(answer[answer.length-1])).join("");
    return answer;
}