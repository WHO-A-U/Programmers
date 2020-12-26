function solution(N, stages) {
  var answer = [];
  let arr = [];
  for (let i = 0; i <= N + 1; i++) {
    arr.push([i, 0]);
  }
  for (let i in stages) {
    arr[stages[i]][1] += 1;
  }
  let cnt = stages.length;
  for (let i in arr) {
    let tmp = arr[i][1];
    arr[i][1] = arr[i][1] / cnt;
    cnt -= tmp;
  }
  arr.shift();
  arr.pop();
  arr.sort((a, b) => {
    if (a[1] < b[1]) return 1;
    if (a[1] > b[1]) return -1;
    if (a[0] < b[0]) return -1;
    return 1;
  });
  answer = arr.map((x) => x[0]);
  return answer;
}
