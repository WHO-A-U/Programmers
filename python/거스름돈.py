def solution(n, money):
    arr = [0]*(n+1)
    arr[0]=1
    for i in money: 
        for idx,val in enumerate(arr):
            if idx-i>=0:
                arr[idx]+=arr[idx-i]
    return arr[n]
