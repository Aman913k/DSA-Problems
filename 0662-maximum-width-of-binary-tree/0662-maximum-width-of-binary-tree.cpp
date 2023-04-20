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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;  
        queue<pair<TreeNode* ,int>> q; 
        q.push({root, 0});
        int ans=0; 
        
        while(!q.empty()){  
            int min_indx=q.front().second;
            int leftmost=0, rightmost=0;
            int size=q.size(); 
                
            for(int i=0; i<size; i++){
                TreeNode* frnt=q.front().first;
                int cur_indx=q.front().second-min_indx;
                q.pop();  
                
                if(i==0) leftmost=cur_indx;
                if(i==size-1) rightmost=cur_indx; 
                if(frnt->left) q.push({frnt->left,(long long)2*cur_indx+1});
                if(frnt->right) q.push({frnt->right,(long long)2*cur_indx+2}); 
                
            }
            ans=max(ans, rightmost-leftmost+1); 
            
        }
        return ans;  
    }
};