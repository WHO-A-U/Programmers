function solution(n, t, m, timetable) {
  var answer = 0;
  timetable = timetable.map(
    (x) => parseInt(x.split(':')[0]) * 60 + parseInt(x.split(':')[1])
  );
  timetable.sort((x, y) => x - y);
  let LASTBUS = (n - 1) * t + 9 * 60;

  if (timetable.filter((x) => x < 540).length >= n * m) {
    answer = timetable[n * m - 1] - 1;
  }

  for (let i = 0; i <= LASTBUS && n > 0; i++) {
    if (n * m > timetable.filter((x) => i >= x).length) {
      answer = Math.max(i, answer);
    }

    if (n > 0 && timetable.filter((x) => i >= x).length < m) {
      answer = Math.max(i, answer);
    }

    if (i >= 540 && (i - 540) % t === 0) {
      for (let j = 0; timetable.length > 0 && j < m; j++) {
        if (timetable[0] <= i) timetable.shift();
        else break;
      }
      n--;
    }
  }
  let a = parseInt(answer / 60);
  let b = answer % 60;
  if (a < 10) a = '0' + a;
  if (b < 10) b = '0' + b;
  return a + ':' + b;
}
