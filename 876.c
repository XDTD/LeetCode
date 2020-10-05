/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* low,*fast;
    low=head;fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        low=low->next;
        fast=fast->next->next;
    }
    return low;
}
