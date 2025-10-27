// Last updated: 10/27/2025, 7:10:22 PM
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        typedef ListNode node;
        node* dummy = new node(-1);
        node* current=dummy;
        while(list1!=NULL&&list2!=NULL){
            if(list1->val<list2->val){
                current->next=list1;
                list1=list1->next;
                current=current->next;
            }
            else{
                current->next=list2;
                list2=list2->next;
                current=current->next;
            }
        }
        while(list1){
            current->next=list1;
            list1=list1->next;
            current=current->next;
        }
        while(list2){
            current->next=list2;
            list2=list2->next;
            current=current->next;
        }
        return dummy->next;
    }
};