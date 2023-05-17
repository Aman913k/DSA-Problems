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
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL) return true;  
        int n=0;
        ListNode* slow=head;
        ListNode* fast=head;    
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;  
            n+=1;
        }
        ListNode* temp=slow;
        
        while(temp!=NULL){
            temp=temp->next;
            n+=1;
        }
        
        ListNode* prev=head;
        ListNode* curr=head->next;
        
        while(curr!=slow){
            ListNode* val=curr->next;
            curr->next=prev;
            
            prev=curr;
            curr=val;
        }      
        head->next=slow; 
        
        if(n%2==1) slow=slow->next;
       
        
        while(slow!=NULL){
            if(slow->val!=prev->val) return false;
            
            slow=slow->next;
            prev=prev->next;  
        }
        
        return true;     
    }
};