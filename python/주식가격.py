def solution(prices):
    answer,s=[0 for i in range(len(prices))],[]
    for idx,val in enumerate(prices):
        if len(s)==0:
            s.append([val,idx]);
        else:
            if s[-1][0] > val:
                while len(s)!=0 and s[-1][0] >val:
                    answer[s[-1][1]]=idx-s[-1][1]
                    s.pop()
            s.append([val,idx])
    for i in s:
        answer[i[1]]=len(prices)-i[1]-1
    return answer
