/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


 //Æ«Âı£¬ÇÒÎ´½ø½×


struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* cur=head,*pre=NULL;
    while(cur!=NULL){
        struct ListNode* next=cur->next;
        cur->next=pre;
        pre=cur;
        cur=next;
    }
    return pre;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    l1=reverseList(l1);
    l2=reverseList(l2);
    struct ListNode* pre=NULL,*head=NULL;
    int Flag=0;
    while(l1!=NULL||l2!=NULL||Flag!=0){
        struct ListNode* cur;
        cur=(struct ListNode*)malloc(sizeof(struct ListNode));
        cur->next=NULL;                                             //·ÀÖ¹²âÊÔ³ö´í
        int val1=(l1==NULL)?0:l1->val;
        int val2=(l2==NULL)?0:l2->val;
        cur->val=val1+val2+Flag;
        Flag=(cur->val>=10);
        cur->val=cur->val>=10?cur->val-10:cur->val;
        if(head==NULL){
            head=cur;
        }
        if(pre!=NULL){
            pre->next=cur;
        }
        pre=cur;
        l1=(l1==NULL)?NULL:l1->next;
        l2=(l2==NULL)?NULL:l2->next;
    }
    return reverseList(head);
}
