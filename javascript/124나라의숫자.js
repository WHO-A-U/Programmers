function solution(n) {
  const arr = [1, 2, 4];
  var answer = [];
  let i = 1;
  while (n - Math.pow(3, i) > 0) {
    n -= Math.pow(3, i);
    i++;
  }
  n--;
  for (; i > 0; i--) {
    answer.unshift(n % 3);
    n = parseInt(n / 3);
  }
  answer = answer.map((x) => arr[x]).join('');
  return answer;
}

// console.log(solution(7));

// console.log(Math.pow(2, 0));

for (let i = 1; i < 100; i++) {
  console.log(solution(i));
}
