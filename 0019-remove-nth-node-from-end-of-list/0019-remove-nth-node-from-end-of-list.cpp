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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        
        for(int i=0; i<n; i++) temp=temp->next;
        
        ListNode* dNode=head;
           
        if(temp==NULL) return head->next;    // EDGE CASE
        
        while(temp->next){
            temp=temp->next;
            dNode=dNode->next;
        }
        
        dNode->next=dNode->next->next;
        return head; 
        
    }
};