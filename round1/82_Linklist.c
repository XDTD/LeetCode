/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 /**
 *   ÑÆ½Úµã
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* pre,*cur,*fast,*preHead;
    preHead=(struct ListNode*)malloc(sizeof(struct ListNode));
    preHead->val=-100;
    preHead->next=head;
    pre=preHead;cur=preHead;fast=preHead->next;
    while(fast!=NULL){
        if(fast->val==cur->val){
            pre->next==NULL;
            while(fast!=NULL&&fast->val==cur->val){
                fast=fast->next;
            }
            pre->next=fast;
            cur=fast;
            fast=(fast==NULL)?NULL:fast->next;
        }
        else{
            fast=fast->next;
            pre=cur;
            cur=cur->next;
        }
    }
    return preHead->next;
}
