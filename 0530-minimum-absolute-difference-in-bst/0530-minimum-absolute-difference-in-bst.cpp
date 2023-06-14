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
    void helper(TreeNode* root, vector<int> &v){
        if(!root) return;     
        
        v.push_back(root->val);    
        
        helper(root->left, v);
        helper(root->right, v);     
        
    
    }
    
    
    int getMinimumDifference(TreeNode* root) {
        
        vector<int> v;
        helper(root, v);
        sort(v.begin(), v.end());
        
        int mini=INT_MAX;
        
        for(int i=1; i<v.size(); i++) mini=min(mini, v[i]-v[i-1]);
        return mini; 
    }
};