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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
    
        while(l1!=NULL){
            s1.push(l1->val);
            l1=l1->next;
        }
        
        while(l2!=NULL){
            s2.push(l2->val);
            l2=l2->next;  
        }
        
        
        
        ListNode* dummy=NULL;
        int carry=0;
        while(!s1.empty() || !s2.empty() || carry!=0){  
            int x=0, y=0;
            
            if(!s1.empty()){
                x=s1.top();
                s1.pop();
            }
            
            if(!s2.empty()){
                y=s2.top();
                s2.pop();
            }     
            
            int sum=x+y+carry;
            int dig=sum%10;
            
            
            ListNode* temp=new ListNode(dig);
            temp->next=dummy;
            dummy=temp;
             
            carry=sum/10;
            
        }
        
        return dummy;
    }
};