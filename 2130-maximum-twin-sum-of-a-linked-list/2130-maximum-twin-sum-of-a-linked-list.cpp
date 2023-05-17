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
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast!=NULL){          // TO FIND THE MIDDLE OF A LINKED-LIST
            slow=slow->next;
            fast=fast->next->next;           
        }
        ListNode* prev=head;
        ListNode* curr= head->next;      
        
        
        while(curr!=slow){            // TO REVERSE THE LINKED-LIST BEFORE THE SLOW POINTER
            ListNode* val=curr->next;
            curr->next=prev;     
            
            prev=curr;     
            curr=val;          
        }
        head->next=slow;  
        
        
        int maxi=INT_MIN;     // PREV BECOMES HEAD OF NEW LINKED-LIST 
        while(slow!=NULL){                            
            maxi=max(maxi, slow->val+prev->val);  
    
            slow=slow->next;
            prev=prev->next;
        }
        
        return maxi; 
    }
};