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
        if(head==NULL) return head;
        
        vector<int> v;
        ListNode* temp=head;
        
        while(temp){
            if(temp->val<x) v.push_back(temp->val);
            temp=temp->next;
        }
        
        temp=head;
        while(temp){
            if(temp->val>=x) v.push_back(temp->val);
            temp=temp->next;
        }
        
        ListNode* dummy=new ListNode(v[0]);
        ListNode*dummyhead=dummy;
        
        for(int i=1; i<v.size(); i++){
            ListNode* temp=new ListNode(v[i]);
            dummy->next=temp;
            dummy=temp;
        }
        dummy->next=NULL; 
        return dummyhead;
        
    }
};