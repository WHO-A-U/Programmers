function J(str1) {
  let A = {};
  let pattern = /^[a-zA-Z]+$/;
  for (let i = 0; i < str1.length - 1; i++) {
    if (pattern.test(str1.substr(i, 2)))
      if (
        Object.keys(A).filter((x) => x === str1.substr(i, 2).toUpperCase())
          .length === 0
      )
        A[str1.substr(i, 2).toUpperCase()] = 1;
      else A[str1.substr(i, 2).toUpperCase()] += 1;
  }
  return A;
}
function solution(str1, str2) {
  let answer = 0;
  let A = J(str1);
  let B = J(str2);
  let arr1 = Object.keys(A);
  let arr2 = Object.keys(B);
  const set = new Set([...arr1, ...arr2]);
  const union = [...set];
  const join = arr1.filter((x) => arr2.includes(x));
  let a = union.reduce((acc, cur) => {
    let a1 = A[cur];
    let b1 = B[cur];
    if (a1 === undefined) a1 = 0;
    if (b1 === undefined) b1 = 0;
    return acc + Math.max(a1, b1);
  }, 0);
  let b = join.reduce((acc, cur) => {
    let a1 = A[cur];
    let b1 = B[cur];
    if (a1 === undefined) a1 = 0;
    if (b1 === undefined) b1 = 0;
    return acc + Math.min(a1, b1);
  }, 0);
  if (a === 0 && b === 0) {
    a = 1;
    b = 1;
  }
  answer = Math.floor((b / a) * 65536);
  return answer;
}
