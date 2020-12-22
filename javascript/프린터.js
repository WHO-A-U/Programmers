function solution(priorities, location) {
  let answer = 1;
  while (true) {
    let sub = priorities.splice(1);
    let head = priorities[0];
    if (sub.filter((x) => x > head).length > 0) {
      priorities = sub.concat(head);
    } else {
      if (location === 0) return answer;
      priorities = sub;
      answer++;
    }
    location = (location - 1 + priorities.length) % priorities.length;
  }
}
