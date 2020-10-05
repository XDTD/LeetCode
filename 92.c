/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    struct ListNode* cur=head,*pre=NULL,*p,*q;
    int HeadFlag=(m==1);
    n=n-m;
    while(m>1){
        pre=cur;
        cur=cur->next;
        m--;
    }
    p=pre;
    q=cur;
    while(n>=0){
        struct ListNode* next=cur->next;
        cur->next=pre;
        pre=cur;
        cur=next;
        n--;
    }
    //����ǰ��
    if(p!=NULL){
        p->next=pre;
    }
    q->next=cur;
    //����Ƿ�תͷָ��
    if(HeadFlag)
        return pre;
    return head;
}
