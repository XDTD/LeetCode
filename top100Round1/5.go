package main

func longestPalindrome(s string) string {
	if s == "" {
		return ""
	}
	start, end := 0, 0
	for i := 0; i < len(s); i++ {
		l1, r1 := expandAroundCenter(s, i, i)
		l2, r2 := expandAroundCenter(s, i+1, i)
		if r1-l1 > end-start {
			start = l1
			end = r1
		}
		if r2-l2 > end-start {
			start = l2
			end = r2
		}
	}
	return s[start : end+1]
}

func expandAroundCenter(s string, l int, r int) (int, int) {
	for ; l > 0 && r < len(s)-1 && s[l-1] == s[r+1]; l, r = l-1, r+1 {
	}
	return l, r
}

func main2() {
	s := "aaaa"
	ans := longestPalindrome(s)
	println(ans)
}
