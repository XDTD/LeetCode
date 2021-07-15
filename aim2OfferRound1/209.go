package main

// 暴力解easy
// 滑动窗口钻了死胡同，待重做
// 注意0还是整个数组的判断

func minSubArrayLen(target int, nums []int) int {
    ans, val  := len(nums), 0   //初始化不是等于0
	l := 0
	for r := 0; r < len(nums); r++{
		val += nums[r]
		for val >= target{
			lenWin := r - l + 1
			if lenWin < ans{
				ans = lenWin
			}
			val -= nums[l]
			l++	
		}
	}
	if l == 0 && ans ==  len(nums) { // 0还是整个数组的判断
		ans = 0
	}
	return ans
}

func main3(){
	target := 11
	nums := []int {1,1,1,1,1,1,1,1}
	a := minSubArrayLen(target, nums)
	println(a)
}