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


void helper(TreeNode* root, vector<int> v[]){
    if(!root) return;
    if(root->left){
        v[root->val].push_back(root->left->val);
        v[root->left->val].push_back(root->val); 
        helper(root->left, v);
    }
    if(root->right){
        v[root->val].push_back(root->right->val);
        v[root->right->val].push_back(root->val); 
        helper(root->right, v); 
    }
}
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        vector<int> adj[100001]; 
        helper(root, adj);
        
        vector<int> vis(100001, 0); 
        queue<int> q;
        q.push(start);
        vis[start]=1; 
        
        int cnt=0;
        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int frnt=q.front();
                q.pop();
                
                for(auto it: adj[frnt]){
                    if(adj[frnt].size()>0) {
                        if(!vis[it]){
                            vis[it]=1;
                            q.push(it);
                        }
                    }
                }
            }
            
            cnt++; 
        }
        
        return cnt-1;    
     
        
    }
};