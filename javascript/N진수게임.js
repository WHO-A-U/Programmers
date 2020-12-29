function solution(n, t, m, p) {
  let answer = '';
  const d = {
    0: '0',
    1: '1',
    2: '2',
    3: '3',
    4: '4',
    5: '5',
    6: '6',
    7: '7',
    8: '8',
    9: '9',
    10: 'A',
    11: 'B',
    12: 'C',
    13: 'D',
    14: 'E',
    15: 'F',
  };
  const stack = [];
  let i = 0;
  let j = 1;
  while (true) {
    if (stack.length === 0) {
      let cur = i;
      let flag = false;
      while (true) {
        stack.push(cur % n);
        cur = Math.floor(cur / n);
        if (cur === 0) break;
      }
    }
    while (stack.length !== 0) {
      let cur = stack.pop();
      if (j === p) {
        answer += d[cur];
        if (answer.length === t) {
          return answer;
        }
      }
      j = (j % m) + 1;
    }
    i++;
  }
}
