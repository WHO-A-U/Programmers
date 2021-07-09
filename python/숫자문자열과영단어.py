from functools import reduce
digit={'zero':'0','one':'1','two':'2','three':'3','four':'4','five':'5','six':'6','seven':'7','eight':'8','nine':'9'}
def sol(s):
    return reduce(lambda ans,d:ans.replace(d,digit[d]),digit.keys(),s)
