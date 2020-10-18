https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * preHead = new ListNode(0, head);
        ListNode* queueHead = preHead, * queueTail = preHead;
        for(int i = 0; i < n; i++){
            queueTail = queueTail->next;
        } 
        while(queueTail->next != nullptr){
            queueHead = queueHead->next;
            queueTail = queueTail->next;
        }
        ListNode* temp = queueHead->next;
        queueHead->next = temp->next;
        return preHead->next;
    }
};