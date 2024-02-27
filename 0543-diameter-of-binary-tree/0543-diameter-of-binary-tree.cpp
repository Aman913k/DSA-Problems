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
    
    int depth(TreeNode* root){
        if(!root) return NULL;       
        return max(1+depth(root->left), 1+depth(root->right));  
    }
    
    
     
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return NULL;
        
        int fromRoot=depth(root->left)+depth(root->right); 
        int checkLeft=diameterOfBinaryTree(root->left);
        int checkRight=diameterOfBinaryTree(root->right);
        
        return max({fromRoot, checkLeft, checkRight});
    }
};