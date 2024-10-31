/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q) return root; 
        
        TreeNode *Left=lowestCommonAncestor(root->left, p, q);
        TreeNode *Right=lowestCommonAncestor(root->right, p, q); 
        
        if(Left&&Right) return root;
        if(Left) return Left;
        return Right;
        
    } 
};