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
    int fg=0;
    unordered_map<int,int> mp;
    void dfs(TreeNode* root, int level, int x, int y){
        if(!root) return;
        if((root->left&&root->right)&&((root->left->val==x&&root->right->val==y)||(root->left->val==y&&root->right->val==x))){
            fg=1;
            return; 
        }
         
        mp[root->val]=level;
        
        dfs(root->left, level+1, x, y);
        dfs(root->right, level+1, x, y);            
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, 0, x, y); 
        if(fg) return 0; 
    
        return mp[x]==mp[y]; 
    }
};