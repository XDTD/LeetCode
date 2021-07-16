package main

// 严格遵循左闭右开，上闭下开的思路即可
// 注意每一轮初始化
// n为单数时最中间不遵循规则另外判断

func generateMatrix(n int) [][]int {
    ans := make([][]int, n)
	for i := 0; i < n; i++{
		ans[i] = make([]int, n)
	}
	left, right := 0, n - 1
	bottom, top := 0, n - 1
	cnt := 0
	for left < right {
		j, i := left, bottom
		for j = left; j < right; j++ {
			cnt++
			ans[i][j] = cnt
		}
		for i = bottom; i < top; i++ {
			cnt++
			ans[i][j] = cnt
		}
		for j = right; j > left ; j-- {
			cnt++
			ans[i][j] = cnt
		}
		for i = top; i > bottom; i--{
			cnt++
			ans[i][j] = cnt
		}
		left++
		right--
		bottom++
		top--
	}
	if n % 2 == 1 {
		ans[n/2][n/2] = n * n
	}
	return ans
}

func main5(){
	n := 3
	a := generateMatrix(n)
	println(a)
}