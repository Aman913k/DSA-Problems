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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessThanX=new ListNode(0);
        ListNode* moreThanX=new ListNode(0);
        
        ListNode* headOfLess=lessThanX;
        ListNode* headOfMore=moreThanX;
        
        
        ListNode* temp=head;
        
        while(temp!=NULL){
            if(temp->val<x){
                lessThanX->next=temp;
                lessThanX=lessThanX->next;
            }
            else{
                moreThanX->next=temp;
                moreThanX=moreThanX->next;
            }
            temp=temp->next;    
        }
        moreThanX->next=NULL;
        lessThanX->next=headOfMore->next;
        
        return headOfLess->next;
        
    }
};