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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int k=1;
        ListNode* temp=head;
    
        
        ListNode* dummy=new ListNode(0);
        ListNode* dummyHead=dummy; 
        stack<int> st; 
        
        while(temp){  
            if(k<=right && k>=left){
                st.push(temp->val);
            }
            temp=temp->next;  
            k++;
        }
        
        
        
        k=1;
        temp=head;
        
        while(temp){ 
            if(k<=right && k>=left){
                ListNode* New= new ListNode(st.top());
                dummy->next=New;
                st.pop();
            }  
            
            else dummy->next=temp;
            
            temp=temp->next;
            dummy=dummy->next;
            k++; 
        }
        
        return dummyHead->next;
    }
};