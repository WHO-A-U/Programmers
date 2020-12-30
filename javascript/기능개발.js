function solution(progresses, speeds) {
  const answer = [];
  let cnt = 0;
  while (progresses.length !== 0) {
    for (let i = 0; i < progresses.length; i++) {
      progresses[i] += speeds[i];
    }
    while (progresses.length !== 0 && progresses[0] >= 100) {
      cnt++;
      progresses.shift();
      speeds.shift();
    }
    if (cnt !== 0) {
      answer.push(cnt);
      cnt = 0;
    }
  }
  return answer;
}
