function solution(s) {
  let answer = [];
  let arr = s
    .substr(1, s.length - 2)
    .split('},{')
    .join('}.{')
    .split('.')
    .map((x) => x.substr(1, x.length - 2).split(','));
  arr.sort((a, b) => (a.length > b.length ? 1 : -1));
  answer = arr.map((x) => {
    let tmp = x[0];
    arr.map((y) => {
      if (y.length > 0) {
        y.splice(y.indexOf(tmp), 1);
      }
    });
    return parseInt(tmp);
  });
  return answer;
}
