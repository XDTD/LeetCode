/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



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

//����ָ�����е㣬��ֲ���
void reorderList(struct ListNode* head) {
    if(head==NULL||head->next==NULL)
        return head;
    struct ListNode *slow,*fast,*pre,*cur;
    slow=head;fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    pre=slow;
    slow=reverseList(slow->next);
    pre->next=NULL;                     //��β��NULL
    pre=head;cur=head;
    //�������
    while(slow!=NULL){
        struct ListNode * tmp=slow;
        slow=slow->next;
        pre=cur;
        cur=cur->next;
        pre->next=tmp;
        tmp->next=cur;
    }
}
