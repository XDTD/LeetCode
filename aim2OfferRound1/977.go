package main

// 思路没问题代码细节需要注意
// 第一次提交没考虑全小于0情况
// 第二次错误是边界值应该是nums[i]最大值平方而不是绝对值
// l>=0而不是 l > 0
// 先二分法找到分界点，然后双指针分别左右跑

func sortedSquares(nums []int) []int {
    ans := make([]int, len(nums))
	l, r := 0, len(nums) - 1
	count, pos := 0, 0
	var mid int
	for l <= r {
		mid = l + (r - l) / 2
		if mid > 0 && nums[mid] >= 0 && nums[mid - 1] < 0 {
			pos = mid
			break
		} else if nums[mid] < 0 {
			l = mid + 1
		} else {
			r = mid - 1
		}
	}
	l, r = pos -1, pos
	for count < len(nums){
		num1, num2 := int(1e8), int(1e8)
		if l >= 0 {
			num1 = nums[l] * nums[l]
		}
		if r < len(nums){
			num2 = nums[r] * nums[r]
		}
		// 不能直接写max
		if(num1 < num2){
			l--
			ans[count] = num1
		}else{
			r++
			ans[count] = num2
		}
		count++ 
	}
	return ans
}

func main2(){
	nums := []int {-10000,-9999,-7,-5,0,0,10000}
	ans := sortedSquares(nums)
	println(ans)
}