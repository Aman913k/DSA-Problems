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
        int carry=0;
        
        ListNode* dummy=new ListNode(0);
        ListNode* head=dummy;
        while(l1!=NULL || l2!=NULL || carry!=0){
            int sum=0;
            int x=0, y=0;
            
            if(l1!=NULL){  
                x=l1->val;
                l1=l1->next;   
            }   
            
            if(l2!=NULL){   
                y=l2->val;
                l2=l2->next;     
            }
            
            sum=x+y+carry;
            int dig=sum%10;
            
            ListNode* temp=new ListNode(dig);
            dummy->next=temp;
            dummy=temp;
            
            carry=sum/10;
        }
        dummy->next=NULL;
        return head->next;
    }
};