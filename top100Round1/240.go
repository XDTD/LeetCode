//
//https://blog.csdn.net/qq_21201267/article/details/102734391
package main

// 二叉树遍历的思路，自己没想出来，双二分查找也没写出来
// 充分利用行列都有序的性质，从左下角或者右上角出发
// 以左下角为例，当前值小于target则当前列其他值都小于target，将列+1
// 当前值大于target则当前行都大于target,将行-1
// 如果是右上角同理

func searchMatrix(matrix [][]int, target int) bool {
	m, n := len(matrix), len(matrix[0])
	row, col := m-1, 0
	for row >= 0 && col < n {
		if matrix[row][col] > target {
			row--
		} else if matrix[row][col] < target {
			col++
		} else {
			return true
		}
	}
	return false
}

func main6() {
	matrix := [][]int{{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}}
	target := 2
	ans := searchMatrix(matrix, target)
	println(ans)
}
