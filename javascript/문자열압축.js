function solution(s) {
  var answer = 0;
  let str, cnt;
  let maxStr, maxCnt;
  let maxLen = 0;
  for (let i = 1; i <= parseInt(s.length / 2); i++) {
    let tmp = {};
    let prev = s.substr(0, i);
    let curLen = 0;
    cnt = 1;
    for (let iter = i; iter < s.length; iter += i) {
      const cur = s.substr(0 + iter, i);
      if (prev === cur) {
        cnt++;
      } else {
        if (cnt >= 2) {
          curLen += prev.length * cnt - (String(cnt).length + prev.length);
        }
        prev = cur;
        cnt = 1;
      }
    }
    if (cnt >= 2) {
      curLen += prev.length * cnt - (String(cnt).length + prev.length);
    }

    console.log(tmp);
    maxLen = Math.max(maxLen, curLen);
    console.log(maxLen);
  }
  //   console.log(str);
  console.log(maxStr, maxCnt);
  return s.length - maxLen;
}
let c = 'xababcdcdababcdcd';
console.log(solution(c));
