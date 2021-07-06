//https://leetcode-cn.com/problems/combination-sum/submissions/
package main

var ans [][]int

func combinationSumSubFunc(candidates []int, target int, cur int, temp []int) {
	if cur == 0 {
		one_of_ans := make([]int, len(temp)) //不做copy的操作切片值会被更改
		copy(one_of_ans, temp)
		ans = append(ans, one_of_ans)
		return
	}
	for i := 0; i < len(candidates); i++ {
		//从小往大排防止重复组合，只有[2 2 3]不会有[3 2 2]和[2 3 2]
		if cur-candidates[i] >= 0 && (len(temp) == 0 || candidates[i] >= temp[len(temp)-1]) {
			temp = append(temp, candidates[i])
			combinationSumSubFunc(candidates, target, cur-candidates[i], temp)
			temp = temp[:len(temp)-1] // 删除尾部1个元素
		}
	}
}

func combinationSum(candidates []int, target int) [][]int {
	ans = nil //不重新初始化leetcode上会积累每个用例的结果
	var one_of_ans []int
	combinationSumSubFunc(candidates, target, target, one_of_ans)
	return ans
}

func main() {
	candidates := []int{2, 3, 5}
	target := 8
	a := combinationSum(candidates, target)
	println(a)
}
