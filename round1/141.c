/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head==NULL||head->next==NULL)
        return false;
    struct ListNode * slow,*fast;
    slow=head;fast=head;
    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next==NULL?NULL:fast->next->next;
        if(slow==fast)
            return true;
    }
    return false;
}
