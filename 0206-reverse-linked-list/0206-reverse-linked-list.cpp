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
        
        ListNode *reverse=NULL, *reverseHead=reverse;
        ListNode *prev=head, *Next=head->next;
        
        while(prev){ 
            Next=prev->next;
            
            prev->next=reverse;
            reverse=prev;
            
            prev=Next;
            
            
        }
          
        return reverse;
        
        
    }
};