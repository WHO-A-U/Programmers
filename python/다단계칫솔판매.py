name={}
money ={}
def go(p_name):
    if p_name not in name:
        ret = []
        for i,earn in enumerate(money[p_name]):
            div = earn//10
            if div>0:
                ret.append(div)
                money[p_name][i]-=div
                
        money[p_name]=sum(money[p_name])
       
        return ret
    
    for child in name[p_name]:
        money[p_name]= money[p_name]+go(child)
    
    ret = []
    for i,earn in enumerate(money[p_name]):
        div = earn//10
        if div>0:
            ret.append(earn//10)
            money[p_name][i]-=div
            
    money[p_name]=sum(money[p_name])    

    return ret

def solution(enroll, referral, seller, amount):
    for ch,pa in zip(enroll,referral):
        if ch not in money:
            money[ch]=[];
        
        if pa in name:
            name[pa].append(ch);
        else:
            name[pa] = [ch]
    money["-"]=[]
    for person,earn in zip(seller,amount):
        money[person].append(earn*100);
    
    go("-")
    answer = []
    for i in enroll:
        answer.append(money[i])
    return answer






