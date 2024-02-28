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
    int maxi=0;
    int ans;
    void helper(TreeNode* root, int height){
        if(!root) return;
        
        if(root->left && !root->left->left && !root->left->right){
            if(height>maxi){
                maxi=height;
                ans=root->left->val;  
            }
        }
        
        else{
            if(height>maxi){
                maxi=height;
                ans=root->val;
            }
        }
        
        
        helper(root->left, height+1); 
        helper(root->right, height+1);       
    }
    
    
    int findBottomLeftValue(TreeNode* root) {
        if(!root->left && !root->right) return root->val; 
        helper(root, 0);
        
        return ans;
    }
};