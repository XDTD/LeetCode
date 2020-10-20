/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:



 ListNode* reverseList( ListNode* head) {
     ListNode* cur=head,*pre=NULL;
    while(cur!=NULL){
         ListNode* next=cur->next;
        cur->next=pre;
        pre=cur;
        cur=next;
    }
    return pre;
}

//快满指针找中点，拆分查找
void reorderList(ListNode* head) {
    if(head==NULL||head->next==NULL)
        return;
     ListNode *slow,*fast,*pre,*cur;
    slow=head;fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    pre=slow;
    slow=reverseList(slow->next);
    pre->next=NULL;
    pre=head;cur=head;
    while(slow!=NULL){
         ListNode * tmp=slow;
        slow=slow->next;
        pre=cur;
        cur=cur->next;
        pre->next=tmp;
        tmp->next=cur;
    }
}
};




//ben bi jie fa
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head){
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return;
        ListNode* second = head->next, *preTail = head;
        while(preTail->next->next != nullptr){
            preTail = preTail->next;
        }
        ListNode* tail = preTail->next;
        preTail->next = nullptr;
        head->next = tail;
        tail->next = second;
        reorderList(second);
    }

};