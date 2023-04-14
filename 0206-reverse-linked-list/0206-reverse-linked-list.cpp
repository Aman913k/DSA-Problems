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
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL; 
        ListNode* prev=head;
        ListNode* temp=head;
        ListNode* curr=head->next;
        
        while(curr!=NULL){   
            ListNode* val=curr->next;     
            curr->next=prev;
            
            prev=curr;  
            curr=val; 
        }
        head->next=NULL;
        return prev;   
    }
};