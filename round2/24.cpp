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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr)
            return head;
        ListNode* pre = new ListNode(0, head);
        ListNode* preHead = pre,  *cur = head;
        while(cur != nullptr && cur->next != nullptr){
            ListNode* temp = cur->next;
            pre->next = temp;
            cur->next = temp->next;
            temp->next = cur;
            pre = cur;
            cur = cur->next;
        }
        return preHead->next;
    }
};