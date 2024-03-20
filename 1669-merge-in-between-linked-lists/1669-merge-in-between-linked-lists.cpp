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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *from=list1, *to=list1, *list2Tail=list2;
        
        while(list2Tail->next) list2Tail=list2Tail->next; 
        
        for(int i=1; i<a; i++) from=from->next;
        for(int i=1; i<=b; i++) to=to->next; 
        
        from->next=list2; 
        list2Tail->next=to->next;      
        
        return list1;    
        
    }
};