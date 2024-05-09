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
    ListNode* doubleIt(ListNode* head) {
        ListNode* temp=head;
        ListNode* tempAdd;
        ListNode* dummy=NULL;
        
        while(temp){
            tempAdd=temp->next;
            temp->next=dummy;
            dummy=temp; 
            temp=tempAdd;
        }
        ListNode* dummyHead=dummy;
        
        int carry=0;
        while(dummy){
            int num=dummy->val*2;
            dummy->val=(num%10)+carry;  
            carry=num/10;
            dummy=dummy->next; 
        }
        temp=dummyHead;
        dummy=NULL;
        
        while(temp){
            tempAdd=temp->next;
            temp->next=dummy;
            dummy=temp; 
            temp=tempAdd;
        }
    
        if(carry){
            ListNode* newNode=new ListNode(carry);
            newNode->next=dummy;
            return newNode; 
        }

        return dummy;
    }
};