function solution(msg) {
  var answer = [];
  const dict = {};
  const keyword = [];
  for (let i = 0; i < 26; i++) {
    keyword.push(String.fromCharCode(i + 'A'.charCodeAt(0)));
    dict[String.fromCharCode(i + 'A'.charCodeAt(0))] = i + 1;
  }
  for (let i = 0; i < msg.length; i++) {
    let j = 1;
    while (i + j <= msg.length) {
      if (keyword.includes(msg.substr(i, j))) {
        j++;
        if (i + j > msg.length) answer.push(dict[msg.substr(i, j)]);
        continue;
      } else {
        answer.push(dict[msg.substr(i, j - 1)]);
        break;
      }
    }
    const word = msg.substr(i, j);
    keyword.push(word);
    dict[word] = keyword.length;
    i += j - 2;
  }
  return answer;
}
