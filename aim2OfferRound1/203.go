package main

// 用虚拟头节点
// 名字叫dummyHead


type ListNode struct {
	Val int
	Next *ListNode
}

func removeElements(head *ListNode, val int) *ListNode {
	dummyHead := &ListNode{}
	dummyHead.Next = head
	temp := dummyHead
	for temp.Next != nil {
		cur := temp.Next
		if cur.Val = val {
			temp.Next = cur.Next
		}else {
			temp = temp.Next
		}
	}
	return dummyHead.Next  
}
