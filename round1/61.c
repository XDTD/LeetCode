/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


 /**
 *讲道理应该快一些的方法
 */
 struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(k<1||head==NULL)
        return head;
    int len=1;
    struct ListNode* cur,*pre,*last;cur=head;
    while(cur->next!=NULL){
        cur=cur->next;
        len++;
    }
    last=cur;
    k=k%len;
    int n=len-k;
    if(k==0)
        return head;
    for(cur=head;n>0;n--){
       pre=cur;
        cur=cur->next;
    }
    pre->next=NULL;
    last->next=head;
    return cur;
}



struct ListNode* rotateRightSingle(struct ListNode* head){
    if(head==NULL||head->next==NULL)
        return head;
    struct ListNode* pre,*cur;
    pre=head;cur=head;
    while(cur->next!=NULL){
        pre=cur;
        cur=cur->next;
    }
    pre->next=NULL;
    cur->next=head;
    return cur;
}

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(k<1||head==NULL)
        return head;
    int len=0;
    struct ListNode* cur,*pre;cur=head;
    while(cur!=NULL){
        cur=cur->next;
        len++;
    }
    k=k%len;
    for(;k>0;k--)
        head=rotateRightSingle(head);
    return head;
}
