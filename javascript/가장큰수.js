function solution(numbers) {
  let ans = numbers
    .map((x) => String(x))
    .sort((x, y) => (x === y ? 0 : parseInt(x + y) > parseInt(y + x) ? -1 : 1))
    .reduce((x, y) => (x += y), '');
  return ans[0] === '0' ? '0' : ans;
}
