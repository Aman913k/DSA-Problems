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
 

void helper(TreeNode* root, string t, string& ans){
    if(!root) return;
    if(!root->left && !root->right){
        t+=char(root->val+'a');
        string rev=t;
        reverse(rev.begin(), rev.end());
        
        if(ans=="") ans=rev;
        else ans=min(ans, rev);
        
        return; 
    }     
    helper(root->left, t+char(root->val+'a'), ans);
    helper(root->right, t+char(root->val+'a'), ans); 
}


class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string t, ans;  

        helper(root, "", ans); 
        return ans;
    }
};