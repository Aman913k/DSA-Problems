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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode* >q;
        q.push(root);
        q.push(NULL);
        int level=0, sum=0, maxi=INT_MIN, ans=0;
        
        while(!q.empty()){    
            
            if(q.front()==NULL){
                q.pop();
                level++;
                if(sum>maxi){
                    ans=level;
                    maxi=sum; 
                }
                   
                if(q.empty()) break;
                sum=0;
                q.push(NULL); 
            }
            
            TreeNode* frnt=q.front();
            q.pop();
            sum+=frnt->val;
            if(frnt->left) q.push(frnt->left);
            if(frnt->right) q.push(frnt->right); 
            
        }
        return ans; 
    }
};