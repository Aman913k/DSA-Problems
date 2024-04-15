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


int helper(TreeNode* root, int tot){
    
    if(!root) return 0;
    if(!root->left && !root->right){  
        return tot=tot*10+root->val;   
    }
    return helper(root->left, tot*10+root->val)+helper(root->right, tot*10+root->val); 
}



class Solution {
public:
    int sumNumbers(TreeNode* root) {
        
        int tot=0;
        return helper(root, tot);
      
    }
};