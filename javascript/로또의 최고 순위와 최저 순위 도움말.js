const prize = {
    6: 1,
    5: 2,
    4: 3,
    3: 4,
    2: 5,
    1: 6,
    0: 6,
  };
  function solution(lottos, win_nums) {
    return [prize[Math.min(lottos.filter((x) => x != 0 && win_nums.includes(x)).length + lottos.filter((x) => x == 0).length, 6)], prize[lottos.filter((x) => x != 0 && win_nums.includes(x)).length]];
  }
  