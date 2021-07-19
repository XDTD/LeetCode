package main

// https://leetcode-cn.com/problems/swap-nodes-in-pairs/submissions/
// 加入虚拟头节点处理更方便，需要返回的虚拟头节点的next
// 每一轮三个节点，分别为当前节点l1，当前节点的下一个节点l2，以及上一组节点中后面那个节点pre
// l1与l2进行交换,pre指向交换后的l2
// 持续直到只剩一个或者空为止
// 虚拟头节点需要进行初始化,此处需要数值以及初始指向head防止只有一个头节点的情况
func swapPairs(head *ListNode) *ListNode {
	dummyHead := &ListNode{-1,head}
	pre := dummyHead
	l1, l2 := head, head
	for l1 != nil && l1.Next != nil {
		//交换节点
		l2 = l1.Next
		next := l2.Next
		l1.Next = next
		l2.Next = l1
		pre.Next = l2
		//更新进入下一轮
		pre = l1
		l1 = next
	}
	return dummyHead.Next
}


func main7() {
	head := &ListNode{1, nil}
	// head.Next = &ListNode{2, nil}
	// head.Next.Next = &ListNode{3, nil}
	// head.Next.Next.Next = &ListNode{4, nil}
	ans := swapPairs(head)
	println(ans)
}
