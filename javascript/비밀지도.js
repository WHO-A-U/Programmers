function solution(n, arr1, arr2) {
  let answer = [];
  for (let i = 0; i < n; i++) {
    let a1 = arr1[i];
    let a2 = arr2[i];
    let c = '';
    for (let j = 1; j <= n; j++) {
      if (a1 % 2 > 0 || a2 % 2 > 0) {
        c = '#' + c;
      } else {
        c = ' ' + c;
      }
      a1 = Math.floor(a1 / 2);
      a2 = Math.floor(a2 / 2);
    }
    answer.push(c);
  }
  return answer;
}
