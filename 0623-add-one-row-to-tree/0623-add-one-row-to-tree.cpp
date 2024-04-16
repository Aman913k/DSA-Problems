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

void helper(TreeNode* root, int val, int indx, int depth){
    if(!root) return; 
    
    if(indx==depth-1){  
        TreeNode* leftAdd=root->left;
        TreeNode* rightAdd=root->right;
        
        TreeNode* newLeft=new TreeNode(val);
        TreeNode* newRight=new TreeNode(val); 
        
        root->left=newLeft;
        root->right=newRight;
        
        root->left->left=leftAdd;
        root->right->right=rightAdd; 
        
        return;
    }
    helper(root->left, val, indx+1, depth);
    helper(root->right, val, indx+1, depth);  
}


class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newRoot=new TreeNode(val);
            newRoot->left=root;
            return newRoot;
        }
        
        helper(root, val, 1, depth);
        return root;
    }
};