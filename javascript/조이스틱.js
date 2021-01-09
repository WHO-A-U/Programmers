function solution(name) {
  let str = name,len = name.length,cnum = 0,cnt = 0,num = 0,minCnt = 20;
    for (let i = 0; i < len; i++) if (str[i] !== 'A') cnum++;
    for(let i=0;i<len;i++){
      if(str[i]!=='A')num++;
      if(num == cnum)break;
      cnt++;
    }
    Math.min(minCnt , cnt);
    cnt =0,num=0;
    for (let j = 0; j < len; j++) {
      for (let i = 0; i < len; i++) {
        if (str[(len-i)%len] !== 'A') num++;
        if (cnum === num) break;
        cnt++;
      }
      minCnt = Math.min(minCnt, cnt + j);
      cnt = 0;
      num=0;
      let tail = str[0];
      let head = str.substr(1, len - 1);
      str = head+tail;
    }
    return (minCnt +str.split('').reduce((acc, val) =>(acc += Math.min(val.charCodeAt() - 'A'.charCodeAt(),'Z'.charCodeAt() - val.charCodeAt() + 1)),0));
  }