const d = {};
let answer = 987654321;
let target;
function go(N, number, cnt) {
  if (cnt > 8) {
    return;
  }
  if (number === target) {
    answer = Math.min(answer, cnt);
  }
  for (let i in d) {
    go(N, number + parseInt(i), cnt + d[i]);
    go(N, number - parseInt(i), cnt + d[i]);
    go(N, number * parseInt(i), cnt + d[i]);
    if (number % parseInt(i) === 0) go(N, number / parseInt(i), cnt + d[i]);
  }
}
function solution(N, number) {
  target = number;
  for (let i = 0; i < 8; i++) {
    d[parseInt(String(N).repeat(i + 1))] = i + 1;
  }
  go(N, 0, 0);
  return answer === 987654321 ? -1 : answer;
}
