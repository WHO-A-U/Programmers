String.prototype.replaceAll = function (a, b) {
  return this.split(a).join(b);
};
function solution(p) {
  var answer = '';
  if (p === '') return '';
  let flag = p[0] === '(' ? true : false;
  let i = 0,
    s = 0;
  for (; i < p.length; i++) {
    if (p[i] === '(') {
      s += 1;
    } else {
      s -= 1;
    }
    if (s === 0) break;
  }
  let v = p.substr(0, i + 1);
  let u = p.substr(i + 1, p.length);
  if (flag) {
    if (i === p.length) return p;
    return v + solution(u);
  } else {
    v = v.replaceAll('(', '.');
    v = v.replaceAll(')', '(');
    v = v.replaceAll('.', ')');
    v = v.substr(1, v.length - 2);
    return '(' + solution(u) + ')' + v;
  }
}
