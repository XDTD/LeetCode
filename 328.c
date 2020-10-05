/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 /**
 *   速度还行，代码不够简洁
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if(head==NULL||head->next==NULL||head->next->next==NULL)
        return head;
    struct ListNode* evenhead=head->next;
    struct ListNode* odd,*even,*tmp;
    odd=head;even=head->next;
    while(odd!=NULL&&odd->next!=NULL){
        tmp=odd;
        odd->next=even->next;
        odd=odd->next;
        even->next=(odd==NULL)?NULL:odd->next;
        even=even->next;
    }
    if(odd==NULL)
        tmp->next=evenhead;
    else
        odd->next=evenhead;
    return head;
}
