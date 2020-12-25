def solution(cacheSize, cities):
    answer = 0
    a=[];
    if cacheSize == 0:
        return len(cities)*5
    for i in cities:
        if i.upper() in a:
            a.remove(i.upper())
            a.append(i.upper())
            answer+=1
        else:
            if len(a) >= cacheSize:
                del(a[0])
            a.append(i.upper())
            answer+=5
    return answer