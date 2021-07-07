package main

// 思路如下
// logn肯定是二分查找，可以通过先找到中间旋转节点的方式来变成常规二分，但是时间复杂度肯定高
// 本来没有太好的思路做优化，尝试查看题解时受到有序无序关键词的启发重新切入
// 常规有序数组可以直接通过mid与target大小来判断下一步搜索左区间还是右区间
// 此题中，无序区间虽然不能直接判断，但是可以通过有序区间是否包含target来判断是否搜索
// 具体展开如下
// 首先左右两边最多有一个无序区间，另一个区间肯定有序，无序区间不好判断通过有序区间来排除
// 如果有序区间包含target，则去搜索有序区间，另外一个区间不用搜索（数组元素不重复）
// 如果有序区间不包含target,另外一个区间可能包含可能不包含（无序区间不好判断），直接去搜索另一个区间
// 重复上述过程，虽然无序区间无法判断是否包含target,但是每次搜索可以排除一个有序区间
// 最后一定可以得到结果或者找不到直接返回-1

func search(nums []int, target int) int {
	ans := -1
	l, r := 0, len(nums)-1
	var mid int
	for l <= r {
		mid = int((l + r) / 2)
		if nums[mid] == target {
			ans = mid
			break
		} else if nums[l] <= nums[mid] { //左区间有序
			if target <= nums[mid] && target >= nums[l] { //左区间包含target找左区间
				r = mid
			} else { //不包含找右区间
				l = mid + 1
			}
		} else if nums[mid+1] <= nums[r] { //右区间有序
			if target <= nums[r] && target >= nums[mid+1] { //右区间包含target找右区间
				l = mid + 1
			} else { //不包含找左区间
				r = mid
			}
		}
	}
	return ans
}

//要测试就去除4写成main
func main4() {
	nums := []int{5, 1, 3}
	target := 0
	ans := search(nums, target)
	println(ans)
}
