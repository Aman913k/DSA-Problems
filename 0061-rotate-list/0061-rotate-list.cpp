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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        int cnt=0;
        ListNode* temp=head;
        
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        
        if(cnt==k) return head;  
        if(k>cnt) k=k%cnt;
        
        cnt=cnt-k;
        
        ListNode* start=head;
        
        while(cnt!=1){
            cnt--;
            start=start->next;
        }
        
        if(start->next==NULL) return head; 
        //cout<<start->val;
        
        ListNode* rem=start->next;
        start->next=NULL; 
            
        ListNode* kth=rem;
        while(rem->next!=NULL) rem=rem->next;
        //cout<<rem->val;
        
        rem->next=head;              
        
        return kth;
    }
};    