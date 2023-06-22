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
    
    int JoinRootRightmost(TreeNode* root){
        if(!root->right){     
            return root->val; 
        }
        return JoinRootRightmost(root->right);
        
        // int value=root->val;
        // while(root->right!=NULL){
        //     value=root->right->val;
        //     root=root->right;
        // }
        // return value; 
    }
    
    
    
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        
        if(root->val==key){
            //if(!root->left && !root->right) return root;
            
            if(!root->right) return root->left;
            else if(!root->left) return root->right;     
              
            root->val=JoinRootRightmost(root->left);
            root->left=deleteNode(root->left, root->val);
             
        }
        
        else if(key<root->val) root->left=deleteNode(root->left, key);
        else if(key>root->val) root->right=deleteNode(root->right, key);
        
        
        return root;
    }
};