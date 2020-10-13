/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
*   快慢指针，跑两次
*/
struct ListNode *detectCycle(struct ListNode *head) {
    if(head==NULL||head->next==NULL)
        return NULL;
    struct ListNode * slow,*fast;
    slow=head;fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            while(head!=slow){
                head=head->next;
                slow=slow->next;
            }
            return head;
        }
    }
    return NULL;

}



