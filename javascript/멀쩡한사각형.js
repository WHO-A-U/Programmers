const GCD = (a, b) => (b > 0 ? GCD(b, a % b) : a);

function solution(w, h) {
  return w * h - (w + h - GCD(w, h));
}
