package main

//https://leetcode-cn.com/problems/coin-change/submissions/
//简单dp,初始化注意下,还有库函数没有max/min

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func coinChange(coins []int, amount int) int {
	dp := make([]int, amount+1)
	dp[0] = 0
	var ans int
	for i := 1; i < amount+1; i++ {
		dp[i] = 10000000
	}
	for i := 1; i < amount+1; i++ {
		for j := 0; j < len(coins); j++ {
			if i-coins[j] >= 0 {
				dp[i] = min(dp[i-coins[j]]+1, dp[i])
			}

		}
	}
	if dp[amount] == 10000000 {
		ans = -1
	} else {
		ans = dp[amount]
	}

	return ans
}

func main() {
	coins := []int{5}
	amounts := 11
	a := coinChange(coins, amounts)
	println(a)
}
