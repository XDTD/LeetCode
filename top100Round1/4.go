package main

import (
	"fmt"
)

func max(x int, y int) int {
	ans := x
	if x < y {
		ans = y
	}
	return ans
}

func min(x int, y int) int {
	ans := y
	if x < y {
		ans = x
	}
	return ans
}

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	n1, n2 := len(nums1), len(nums2)
	if n1 < n2 {
		return findMedianSortedArrays(nums2, nums1)
	}
	mid1 := int(n1 / 2)
	mid2 := int((n1+n2)/2 - mid1)
	for mid1 > 0 && mid2 >= 0 && mid2 < n2 && nums1[mid1-1] > nums2[mid2] {
		mid1--
		mid2 = (n1+n2)/2 - mid1
	}
	for mid2 > 0 && mid1 >= 0 && nums2[mid2-1] > nums1[mid1] {
		mid2--
		mid1 = (n1+n2)/2 - mid2
	}

	ans := .0
	t1, t2, t3, t4 := 0, 1000000, 0, 1000000
	if mid1 > 0 {
		t1 = nums1[mid1-1]
	}
	if mid1 < n1 {
		t2 = nums1[mid1]
	}
	if mid2 > 0 {
		t3 = nums2[mid2-1]
	}
	if mid2 < n2 {
		t4 = nums2[mid2]
	}
	if (n1+n2)%2 == 1 {
		ans = float64(min(t2, t4))
	} else {
		ans = float64(max(t1, t3)+min(t2, t4)) / 2
	}
	return ans
}

func main1() {
	nums1 := []int{4}
	nums2 := []int{1, 2, 3}
	fmt.Printf("%f", findMedianSortedArrays(nums1, nums2))
}
