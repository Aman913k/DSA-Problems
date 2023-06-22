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
    void helper(TreeNode* root, TreeNode* parent, TreeNode* x,  vector<TreeNode*>& v){
        if(root==NULL) return;
        
        if(x->val<root->val){
            v.push_back(root);
            helper(root->left, root, x, v);
        }
        
        else if(x->val>root->val){
            v.push_back(root);
            helper(root->right, root, x, v);   
        }
        
        else{
            v.push_back(root);;
            return;
        }
        
    }
    
    
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> vp, vq;
        helper(root, NULL, p, vp);
        helper(root, NULL, q, vq);
         
        reverse(vp.begin(), vp.end());
        reverse(vq.begin(), vq.end());
        
        
        unordered_map<int, int> mp;
        for(auto i:vp) mp[i->val]++;
        
        int mini=1e9+1;
        for(auto i:vq){     
            if(mp[i->val]){
                 mini=i->val;
                break; 
            }
        }     
    
        TreeNode* node=new TreeNode(mini);
        return node;     
        
    }
};