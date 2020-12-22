function verify(x) {
  let cnt = x.filter((z) => z >= 0).length;
  if (cnt === 0) return true;
  let pre = x[0],
    i;
  for (i = 1; i < x.length; i++) {
    if (pre === -1) return false;
    cnt--;
    if (cnt === 0) return true;
    if (x[i] === -1) return false;
    if (pre > x[i]) return false;
    pre = x[i];
  }
  return true;
}
function solution(skill, skill_trees) {
  var answer = 0;
  const s = skill.split('');
  for (let i in skill_trees) {
    let a = [];
    for (let j in s) {
      a.push(skill_trees[i].indexOf(s[j]));
    }
    if (verify(a)) answer++;
  }
  return answer;
}
