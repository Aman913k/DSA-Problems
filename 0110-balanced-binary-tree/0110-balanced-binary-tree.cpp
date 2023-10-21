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

bool ans=true;
int helper(TreeNode* node){
    if(!node) return 0;  
    int l=0, r=0;   
    
    if(node->left) l=helper(node->left);  
    if(node->right) r=helper(node->right);
    
    return max(l,r)+1;     
}
class Solution {
public:  
    
    bool isBalanced(TreeNode* root) {
        if(!root) return 1; 
        int left=helper(root->left);
        int right=helper(root->right);
        
        return (abs(left-right)<=1 && isBalanced(root->left) && isBalanced(root->right));    
    }
};