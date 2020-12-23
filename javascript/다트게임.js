function solution(dartResult) {
  var answer = 0;
  let arr = [];
  for (let i = 0; i < dartResult.length; i++) {
    console.log(i);
    if (Number(dartResult[i]) >= 0 && Number(dartResult[i + 1]) >= 0) {
      arr.push(dartResult[i] + dartResult[i + 1]);
      i++;
    } else {
      arr.push(dartResult[i]);
    }
  }
  let pre = 0,
    cur = 0;
  for (let i in arr) {
    if (Number(arr[i]) >= 0) {
      answer += pre;
      pre = cur;
      cur = parseInt(arr[i]);
    } else {
      switch (arr[i]) {
        case 'S':
          break;
        case 'D':
          cur = Math.pow(cur, 2);
          break;
        case 'T':
          cur = Math.pow(cur, 3);
          break;
        case '*':
          cur *= 2;
          pre *= 2;
          break;
        case '#':
          cur *= -1;
          break;
      }
    }
  }
  answer += pre + cur;
  return answer;
}
