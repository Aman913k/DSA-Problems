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


void helper(TreeNode* root, int tot, int &ans){
    
    if(!root) return;
    if(!root->left && !root->right){  
        tot=tot*10+root->val;  
        ans+=tot;
    
        tot/=10;
        return;  
    }
    helper(root->left, tot*10+root->val, ans);
    helper(root->right, tot*10+root->val, ans); 
}



class Solution {
public:
    int sumNumbers(TreeNode* root) {
        
        int tot=0, ans=0;
        if(!root) return NULL;
        helper(root, tot, ans);
        
        return ans;
    }
};