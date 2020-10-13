/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if(head==NULL||head->next==NULL)
        return head;
    struct ListNode* L=head->next;
    struct ListNode* cur=L->next,*pre=head;
    L->next=head;
    pre->next=cur;
    while(cur!=NULL){
        struct ListNode* next=cur->next;
        if(next==NULL)
            break;
        else{
            pre->next=next;
            cur->next=next->next;
            next->next=cur;
            pre=cur;
        }
        cur=cur->next;
    }
    return L;
}
