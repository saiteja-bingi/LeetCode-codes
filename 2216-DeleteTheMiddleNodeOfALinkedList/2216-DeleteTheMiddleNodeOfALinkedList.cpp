// Last updated: 10/27/2025, 7:06:04 PM
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
    ListNode* deleteMiddle(ListNode* head) {
        typedef ListNode node;
        int c=0;
        node* temp=head;
        while(temp!=NULL){
            c++;
            temp=temp->next;
        }
        temp=head;
        if(temp->next==NULL) return nullptr;
        for(int i=0;i<c/2-1;i++){
            temp=temp->next;
        }
        node* del = temp->next;
        temp->next=temp->next->next;
        delete del;
        return head;
        
    }
};