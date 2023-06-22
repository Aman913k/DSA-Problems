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
    void helper(TreeNode* root, TreeNode* parent, TreeNode* x,  vector<int>& v){
        if(root==NULL) return;
        
        if(x->val<root->val){
            v.push_back(root->val);
            helper(root->left, root, x, v);
        }
        
        else if(x->val>root->val){
            v.push_back(root->val);
            helper(root->right, root, x, v);   
        }
        
        else{
            v.push_back(root->val);;
            return;
        }
        
    }
    
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> vp, vq;
        helper(root, NULL, p, vp);
        helper(root, NULL, q, vq);
        
        int minIndx=min(vp.size(), vq.size());
        
        int mini=0;
        for(int i=minIndx-1; i>=0; i--){
            if(vp[i]==vq[i]){
                mini=vp[i];
                break;
            }
        }         
    
        
        TreeNode* node=new TreeNode(mini);
        return node;     
    }
};