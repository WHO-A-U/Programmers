def solution(record):
    answer = []
    user={}
    for i in record:
        s = i.split(' ')
        print(s);        
        if s[0]=="Enter":
            user[s[1]]=s[2]
        elif s[0]=="Change":
            user[s[1]]=s[2]
    
    print(user)
    for i in record:
        s = i.split(' ')
        if s[0]=="Enter":
            answer.append(user[s[1]]+"님이 들어왔습니다.")
        elif s[0]=="Leave":
            answer.append(user[s[1]]+"님이 나갔습니다.")
    return answer
