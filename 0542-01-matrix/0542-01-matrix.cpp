class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        vector<vector<int>> ans(n, vector<int> (m));
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        queue<pair<pair<int,int>,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0) q.push({{i,j},0});
            }
        }
        
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dist=q.front().second;
            
            q.pop(); 
            
            ans[row][col]=dist;
            
            int delrow[]={0,1,0,-1};
            int delcol[]={-1,0,1,0};
            
            for(int i=0; i<4; i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && mat[nrow][ncol]==1 && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},dist+1});
                }
            }
            
        }
        
        return ans;

    }
};