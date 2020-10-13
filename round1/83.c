/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    int tmp=head->val;
    struct ListNode* pre,cur;
    pre=head;cur=head->next;
    while(cur!=NULL){
        if(cur->val==tmp){
            pre->next=cur->next;
            cur=cur->next;
        }
        else{
            tmp=cur->val;
            pre=cur;
            cur=cur->next;
        }
    }
    return head;
}
