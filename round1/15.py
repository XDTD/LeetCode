def threeSum(nums):
    """
    :type nums: List[int]
    :rtype: List[List[int]]
    """
    nums.sort()
    res = []
    while i < len(nums)-2:
        l = i + 1
        r = len(nums) - 1
        while l < r:
            if nums[i] + nums[l] + nums[r] < 0:
                l = l +1
                while l < r and nums[l] == nums[l+1]:
                    l = l + 1
            elif nums[i] + nums[l] + nums[r] > 0:
                r = r -1
                while l < r and nums[r] == nums[r-1]:
                    r = r -1
            else:
                res.append([nums[i],nums[l],nums[r]])
                l = l + 1
        while nums[i] == nums[i+1]
    return res


if __name__ == '__main__':
    a = [-1,0,1,2,-1,-4]
    res = threeSum(a)
    print(res)
