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
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans; 
            
        queue<TreeNode*> q;
        q.push(root);
        
        int sz=q.size();
        int maxi=INT_MIN; 
        
        while(sz>0){
            auto tp=q.front();
            q.pop();
            
            if(tp->left) q.push(tp->left);
            if(tp->right) q.push(tp->right);  
            
            if(sz>0) maxi=max(maxi, tp->val); 
            sz--;
            
            if(sz==0){
                ans.push_back(maxi);
                maxi=INT_MIN;
                sz=q.size();   
            }
        
        }
        
        return ans; 
        
    }
};