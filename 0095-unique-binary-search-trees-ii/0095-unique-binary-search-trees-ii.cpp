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

vector<TreeNode*> helper(int s, int e){
    vector<TreeNode*> ans;
    
    if(s>e){
        return {NULL};
    }
    
    for(int i=s; i<=e; i++){
        vector<TreeNode*> leftSubTree=helper(s, i-1);
        vector<TreeNode*> rightSubTree=helper(i+1, e);
        
        
        for(auto left: leftSubTree){
            for(auto right: rightSubTree){

                TreeNode* root=new TreeNode(i);
                root->left=left;
                root->right=right;
                
                ans.push_back(root);
            }
        }
        
    }
    
    return ans;
}


class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
       return helper(1, n);
    }
};