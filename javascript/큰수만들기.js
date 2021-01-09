function solution(number, k) {
  let i = 0;
  let arr = [parseInt(number[i++])];
  while (i < number.length) {
    const cur = parseInt(number[i++]);
    while (k > 0 && arr.length > 0 && arr[arr.length - 1] < cur) {
      arr.pop();
      k--;
    }
    arr.push(cur);
  }
  return arr.join('').substr(0, number.length - k);
}
