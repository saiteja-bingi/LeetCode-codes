// Last updated: 10/27/2025, 7:07:57 PM
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
typedef ListNode node;
node* reverse(node* head){
    if(head==NULL||head->next==NULL) return head;
    node* newhead=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
class Solution {
public:
    bool isPalindrome(ListNode* head) {
    node* slow=head;
    node* fast=head;
    while(fast->next!=NULL&&fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    node* newhead=reverse(slow->next);
    node* first=head;
    node* second=newhead;
    while(second!=NULL){
        if(first->val!=second->val){
            reverse(newhead);
            return 0;
        }
        first=first->next;
        second=second->next;
    }
    reverse(newhead);
    return 1;

}
};