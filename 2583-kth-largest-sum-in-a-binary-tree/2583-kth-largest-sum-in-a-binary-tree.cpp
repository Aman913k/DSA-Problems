/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define ll long long
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<ll> pq;
        queue<TreeNode* > q;
        q.push(root);
        q.push(NULL); 
 
        int level=1; 
        
        while(!q.empty()){
            ll tot=0;          
            
            while(q.front()!=NULL){ 
                auto frnt=q.front();
                q.pop();
                tot+=frnt->val;
                if(frnt->left) q.push(frnt->left);
                if(frnt->right) q.push(frnt->right);
                 
            }
            if(q.front()==NULL && q.size()==1){
                pq.push(tot); 
                break;  
            }
            q.pop(); 
            q.push(NULL); 
            pq.push(tot);
        }
        ll ans=0;
    
        if(k>pq.size()) return -1;
        while(k--){
            ans=pq.top();
            pq.pop();
        }
        
        return ans; 
    }
};