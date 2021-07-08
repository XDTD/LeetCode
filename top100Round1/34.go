package main

// 代码应该可以更精简化
// 思路如下
// 要求为找左边界和右边界，先二分找到其中一个target位置，然后根据target划分左右区间
// 左区间当nums[mid] = target或者nums[mid] > target时都需要向左搜索，否则向右
// 结束条件是到达数组边界或者找到左边界，即当前数等于而左边的数不等于target
// 右区间当nums[mid] = tarhet或者nums[mid] < target时都需要向右搜索，否则向左,
// 结束条件是到达数组边界或者找到右边界，即当前数等于而右边的数不等于target
// 代码写的时候注意二分查找写的形式
// 左右区间划分时可以按当前l 和 r的位置缩小搜索范围

//flag是0往左查询，是1往右查询
func searchLandR(nums []int, target int, flag int) int {
	l, r := 0, len(nums)-1
	ans := 0
	var mid int
	for l <= r {
		mid = l + (r-l)/2
		// 不等于target可以不分flag，按照常规二分进行
		if nums[mid] < target {
			l = mid + 1
		} else if nums[mid] > target {
			r = mid
		} else if nums[mid] == target {
			if flag == 0 {
				if mid == 0 || nums[mid-1] != nums[mid] {
					ans = mid
					break
				} else {
					ans = mid
					r = mid
				}
			} else { //flag == 1
				if mid == len(nums)-1 || nums[mid] != nums[mid+1] {
					ans = mid
					break
				} else {
					ans = mid
					l = mid + 1
				}
			}
		}
	}
	return ans
}

func searchRange(nums []int, target int) []int {
	l, r := 0, len(nums)-1
	ans := []int{-1, -1}
	var mid int
	for l <= r {
		mid = l + (r-l)/2
		if nums[mid] == target {
			// go的数组划分是 0:n 为 nums[0] 到 nums[n-1]
			ans[0] = l + searchLandR(nums[l:mid+1], target, 0)
			ans[1] = mid + searchLandR(nums[mid:r+1], target, 1)
			break
		} else if nums[mid] < target {
			l = mid + 1
		} else {
			r = mid - 1
		}
	}
	return ans
}

//测试改成main
func main1() {
	nums := []int{2, 2}
	target := 2
	ans := searchRange(nums, target)
	println(ans)
}
