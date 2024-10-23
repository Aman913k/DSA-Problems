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
void dfs2(TreeNode* root, vector<int>& levelSum, int level){
    
    if(!root) return; 
    int sibSum=0;  

    if(root->left) sibSum=root->left->val;
    if(root->right) sibSum+=root->right->val; 
    
    
    if(root->left) root->left->val=levelSum[level+1]-sibSum;
    if(root->right) root->right->val=levelSum[level+1]-sibSum; 
    
    dfs2(root->left, levelSum, level+1);   
    dfs2(root->right, levelSum, level+1);     
    

     
}
  
void dfs1(TreeNode* root, vector<int>& levelSum, int level){
    if(!root) return;   
    levelSum[level]+=root->val;
    dfs1(root->left, levelSum, level+1); 
    dfs1(root->right, levelSum, level+1); 
}

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> levelSum(1e5);
        root->val=0;     
        dfs1(root, levelSum, 0);  
        dfs2(root, levelSum, 0); 
        
        
        return root;    
    }
};