//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
        
    void dfs(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &vis)
    {   
         int n=grid.size();
        int m=grid[0].size();
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j]==1 || grid[i][j]==0)
            return;
        vis[i][j]=1;
        
        dfs(i-1,j,grid,vis);
        dfs(i+1,j,grid,vis);
        dfs(i,j-1,grid,vis);
        dfs(i,j+1,grid,vis);
    }
    
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        
        for(int i=0;i<n;i++)
        {
            
            if(grid[i][0]==1)
                dfs(i,0,grid,vis);
            if(grid[i][m-1]==1)
                dfs(i,m-1,grid,vis);
        }
        
         for(int j=0;j<m;j++)
        {
            
            if(grid[0][j]==1)
                dfs(0,j,grid,vis);
            if(grid[n-1][j]==1)
                dfs(n-1,j,grid,vis);
        }
        
        int ct=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                    ct++;
            }
        }
        
        return ct;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends