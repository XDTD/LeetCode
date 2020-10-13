/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


 /**
 *  快慢指针+反转链表
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


bool isPalindrome(struct ListNode* head) {
    if(head==NULL||head->next==NULL){
        return true;
    }
    struct ListNode* low,*fast;
    low=head;fast=head;
    while(fast!=NULL){
        if(fast->next==NULL){           //链表长度为奇数时
          low=low->next;
            break;
        }
        low=low->next;
        fast=fast->next->next;
    }
    low=reverseList(low);
    while(low!=NULL){
        if(low->val!=head->val)
            return false;
        low=low->next;
        head=head->next;
    }
    return true;
}
