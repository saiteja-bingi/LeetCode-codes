// Last updated: 10/27/2025, 7:09:05 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // step-1 detecting a loop
        // step-2 moving them simultaneously by one step
        typedef ListNode node;
        node* slow=head;
        node* fast=head;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }
        if(fast==NULL||fast->next==NULL){
        return nullptr;
        }
        slow=head;
        while(1){
            if(slow==fast) return slow;
            slow=slow->next;
            fast=fast->next;
        }
    }
};