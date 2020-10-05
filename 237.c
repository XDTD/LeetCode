/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode* tmp;
    while(node->next!=NULL){
        node->val=node->next->val;
        tmp=node;
        node=node->next;
    }
    tmp->next=NULL;
}
