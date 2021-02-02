def solution(nums):
    a =set(nums)
    return min(len(a),len(nums)/2)