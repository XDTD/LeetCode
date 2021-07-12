package main

// 缺logn的思路，需要重做
// 维护的序列会记住前面一个最大长度的序列，将新数据插入中间替换
// 不会直接删除那些后面的数据
// 注意找到左边小于目标，右边大于目标的下标二分查找写法
func lengthOfLIS(nums []int) int {
	ans := 1
	if len(nums) == 0 {
		return 0
	}
	d := make([]int, len(nums)+1)
	d[ans] = nums[0]
	for i := 1; i < len(nums); i++ {
		if nums[i] > d[ans] {
			ans++
			d[ans] = nums[i]
		} else {
			l, r := 1, ans
			var mid int
			pos := 0
			for l <= r {
				mid = l + (r-l)/2
				if d[mid] < nums[i] {
					pos = mid
					l = mid + 1
				} else {
					r = mid - 1
				}
			}
			d[pos+1] = nums[i]
		}
	}
	return ans
}

func main7() {
	nums := []int{1, 3, 6, 7, 9, 4, 10, 5, 6}
	a := lengthOfLIS(nums)
	println(a)
}
