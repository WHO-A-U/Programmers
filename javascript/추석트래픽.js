function solution(lines) {
  var answer = 0;
  const time = [];
  lines = lines.map((x) => x.split(' '));

  for (let i of lines) {
    const tmp = i[1].split(':');
    let h = parseInt(tmp[0]) * 3600 * 1000;
    let m = parseInt(tmp[1]) * 60 * 1000;
    let s = parseFloat(tmp[2]) * 1000;
    let exs = parseFloat(i[2].substr(0, i[2].length - 1)) * 1000;
    time.push([h + m + s - exs, h + m + s]);
  }
  time.sort((a, b) => a[1] - b[1]);
  let curTime;
  for (let i = 0; i < time.length; i++) {
    curTime = time[i][1] - 1;
    answer = Math.max(
      answer,
      time.filter((x) => {
        if (x[0] >= curTime && x[0] < curTime + 1000) {
          return 1;
        }
        if (x[0] < curTime && x[1] > curTime) {
          return 1;
        }
      }).length
    );
  }
  return answer;
}
