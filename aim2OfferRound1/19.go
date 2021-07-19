package main

// 快慢指针，先让快指针跑n次，然后快慢指针一起跑
// 当快指针到达链表尾，删除慢指针下一个节点即可
// 注意两个指针初始化应该是虚拟头节点，避免只有一个头节点的特殊情况

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	dummyHead := &ListNode{-1,head}
	slow, fast := dummyHead, dummyHead
	for n > 0 {
		n--
		fast = fast.Next
	}
	for fast.Next != nil {
		slow = slow.Next
		fast = fast.Next
	}
	slow.Next = slow.Next.Next
	return dummyHead.Next
}
