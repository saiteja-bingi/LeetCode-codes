// Last updated: 10/27/2025, 7:09:48 PM
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
    ListNode* rotateRight(ListNode* head, int k) {
        typedef ListNode node;
        if(head==NULL||head->next==NULL) return head;
        node* temp=head;
        int n=0;
        node* last;
        while(temp!=NULL){
            n++;
            if(temp->next==NULL){
                last=temp;
            }
            temp=temp->next;
        }
        if(k==0||k%n==0) return head;
        temp=head;
        for(int i=1;i<n-(k%n);i++){
            temp=temp->next;
        }
        node* newhead=temp->next;
        temp->next=NULL;
        last->next=head;
        return newhead;
    }
};