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
    map<int, int> mp;
    int ans=0;
      
    void helper(TreeNode* root){
        mp[root->val]++;
        if(!root->left && !root->right){
            int x=0;
            for(auto i: mp) if(i.second%2==1) x++;
            if(x<=1) ans++;
            mp[root->val]--;
            return;
        }
        if(root->left) helper(root->left);
        if(root->right) helper(root->right);
        mp[root->val]--;
    }
    
    
    int pseudoPalindromicPaths (TreeNode* root) {

        helper(root);
        return ans;
        
    }
};