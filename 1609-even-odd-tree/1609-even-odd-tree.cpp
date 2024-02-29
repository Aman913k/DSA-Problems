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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode* > q;
        q.push(root);
        q.push(NULL);
        
        int level=0; 
        vector<int> v;
        
        while(q.size()){         
            TreeNode* frnt=q.front(); 
            q.pop();
            if(frnt && frnt->left) q.push(frnt->left);
            if(frnt && frnt->right) q.push(frnt->right);
            
            if(frnt==NULL && q.empty()) break;  
            
            if(frnt) v.push_back(frnt->val);         
            
            if(frnt==NULL){
                q.push(NULL);
                
                if(level%2==1){
                    if(v[0]%2==1) return false; 
                    for(int i=1; i<v.size(); i++) if(v[i]>=v[i-1] || v[i]%2==1) return false;
                    v.clear();    
                }               
                
                else{    
                    if(v[0]%2==0) return false;
                    for(int i=1; i<v.size(); i++) if(v[i]<=v[i-1] || v[i]%2==0) return false;
                    v.clear();
                }       
                
                level++; 
            }  
        }
        
        if(level%2==1){
            if(v[0]%2==1) return false;
            for(int i=1; i<v.size(); i++) if(v[i]>=v[i-1] || v[i]%2==1) return false;
        }
        
        else{
            if(v[0]%2==0) return false;
            for(int i=1; i<v.size(); i++) if(v[i]<=v[i-1] || v[i]%2==0) return false;
        }
        
        return true; 
    }
};