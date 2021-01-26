def solution(s):
    answer  , dp =  0 ,[[-1 for i in range(len(s))] for j in range(len(s))]
    if len(s)>0:answer=1
    for i in range(len(s)):
        for j in range(len(s)):
            if i==0:
                dp[j][j]=1
                dp[j][j-1]=0
            elif j+i<len(s) and s[j]==s[j+i] and j<=j+i-1 and  dp[j+1][j+i-1]>= 0:
                dp[j][j+i]=dp[j+1][j+i-1]+2
                answer = max(answer,dp[j][j+i])
    return answer