function solution(files) {
  var answer = [];
  for (let i of files) {
    let head = '',
      number = '',
      tail = '',
      j = 0;
    for (; j < i.length && (isNaN(i[j]) || i[j] == ' '); j++) {
      head += i[j];
    }
    for (; j < i.length && Number(i[j]) >= 0; j++) {
      number += i[j];
    }
    for (; j < i.length; j++) {
      tail += i[j];
    }
    answer.push([head, number, tail]);
  }
  console.log(answer);
  answer.sort((a, b) => {
    if (a[0].toUpperCase() < b[0].toUpperCase()) {
      return -1;
    }
    if (a[0].toUpperCase() > b[0].toUpperCase()) {
      return 1;
    }
    if (parseInt(a[1]) < parseInt(b[1])) {
      return -1;
    }
    if (parseInt(a[1]) > parseInt(b[1])) {
      return 1;
    }
    return 0;
  });
  answer = answer.map((x) => x[0] + x[1] + x[2]);
  return answer;
}
