def twoSum(nums ,target ):
    require_list = {}
    for i,num in enumerate(nums):
        if num in require_list.keys():
            return [require_list[num],i]
        else:
            require_list[target - num] = i
    return None


if __name__ == '__main__':
    nums = [2,7,11,15]
    a = twoSum(nums, 9)
    print(a)
    b={}
    