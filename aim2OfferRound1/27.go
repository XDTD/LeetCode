package main

//https://leetcode-cn.com/problems/remove-element/submissions/
//快慢指针反向写法？

func removeElement(nums []int, val int) int {
	count := 0
	for i := 0; i < len(nums); i++{
		if nums[i] == val{
			count++
		}else{
			nums[i-count] = nums[i]
		}
	}
	return len(nums) - count
}

func main(){
	nums := []int{0,1,2,2,3,0,4,2}
	val := 2
	a := removeElement(nums, val)
	println(a)
}