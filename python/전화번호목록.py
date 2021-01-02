def solution(phone_book):
    Map={}
    for i in phone_book:
        Map[i]=1
    for i in phone_book:
        for j in range(0,len(i)):
            if i[:j+1] in Map:
                return False
    return True
