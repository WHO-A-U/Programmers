function isPossible(distance, rocks, n, mid) {
  if (mid > distance) return false;
  let arr = [];
  for (let i = 1; i < rocks.length; i++) arr.push(rocks[i] - rocks[i - 1]);
  let i = 0;
  console.log(mid);
  while (true) {
    if (i > arr.length - 2) break;
    if (arr[i] >= mid) {
      i++;
      continue;
    } else {
      arr.splice(i, 2, arr[i] + arr[i + 1]);
      continue;
    }
  }
  console.log(arr);
  if (arr[arr.length - 1] < mid) {
    while (true) {
      if (arr.length <= 1 || arr[arr.length - 1] >= mid) {
        break;
      }
      arr.push(arr.pop() + arr.pop());
    }
  }
  return rocks.length - arr.length - 1 <= n ? true : false;
}

function solution(distance, rocks, n) {
  var answer = 0;
  rocks.push(0, distance);
  rocks.sort((x, y) => x - y);
  console.log(rocks);
  let l = 1,
    r = 1000000000,
    mid,
    ans;
  while (true) {
    mid = Math.floor((l + r) / 2);
    console.log('L ', l, ' R ', r, ' mid : ', mid);
    if (isPossible(distance, rocks, n, mid)) {
      console.log('pass');
      ans = mid;
      l = mid + 1;
    } else {
      console.log('fail');
      r = mid - 1;
    }
    if (l > r) {
      return ans;
    }
  }
  return answer;
}

// const a = (b) => {
//   b.push(1);
//   for (let i of b) {
//     console.log(i);
//   }
// };

// v = [5, 6, 7, 8];
// a(v);

d1 = 25;
r1 = [2, 14, 11, 21, 17];
n1 = 2;
// isPossible(d1, r1, n1, 4);
console.log(solution(d1, r1, n1));
// r1.push(r1.pop() + r1.pop());
// console.log(r1);
