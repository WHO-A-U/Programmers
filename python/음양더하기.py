def solution(absolutes, signs):
    return sum(list(map(lambda x:x[0] if x[1] else -x[0],zip(absolutes,signs))))