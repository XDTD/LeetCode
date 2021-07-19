package main

//链表初始化，测试用例怎么写要注意
//预节点要初始化为nil,开始不用指向head

func reverseList(head *ListNode) *ListNode {
	var pre *ListNode= nil
	cur := head
	for cur != nil {
		next := cur.Next
		cur.Next = pre
		pre = cur
		cur = next
	}
	return pre
}

func main6(){
	head := &ListNode{1, nil}
	a := &ListNode{2, nil}
	head.Next = a
	head.Next.Next = &ListNode{3, nil}
	head.Next.Next.Next = &ListNode{4, nil}
	b := reverseList(head)
	println(b)
}