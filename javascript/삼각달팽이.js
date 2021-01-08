function solution(n) {
  var answer = [];
  for (let i = 1; i <= n; i++) answer.push(Array(i));
  let k = 1,
    r = 0,
    c = 0,
    size = n;
  for (let i = 0; i <= parseInt((n - 1) / 3); i++, size -= 3, r += 2, c += 1) {
    for (let j = 0; j < size; j++) answer[j + r][c] = k++;
    for (let j = 0; j < size - 2; j++) answer[r + size - 1][j + c + 1] = k++;
    for (let j = size - 1; j >= 1; j--) answer[r + j][c + j] = k++;
  }
  return [].concat(...answer);
}
