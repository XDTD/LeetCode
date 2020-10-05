/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//速度还行

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if(head==NULL||k<2)
        return head;
    int len=0,n;
    struct ListNode* cur,*pre,*tmp=NULL;
    cur=head;
    while(cur!=NULL){
        len++;
        cur=cur->next;
    }
    n=len/k;
    cur=head;
    while(n>0){
        int cnt=k;
        struct ListNode* tmpPre=tmp;
        tmp=cur;
        pre=NULL;
        while(cnt>0){
            cnt--;
            struct ListNode* next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        if(n==len/k){
            head=pre;
        }
        if(tmpPre!=NULL)
            tmpPre->next=pre;
        tmp->next=cur;
        n--;
    }
    return head;

}
