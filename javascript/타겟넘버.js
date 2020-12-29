function solution(numbers, target) {
  let answer = [];
  answer.push(numbers[0], -numbers[0]);
  console.log(answer);
  for (let i = 1; i < numbers.length; i++) {
    answer = answer
      .map((x) => x + numbers[i])
      .concat(answer.map((x) => x - numbers[i]));
  }
  return answer.filter((x) => x == target).length;
}
