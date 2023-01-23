//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,vector<pair<int,int>>& vp,int r,int c)
    {   
           int n=grid.size();
        int m=grid[0].size();
        
        
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0 || vis[i][j])
            return ;
        
        vis[i][j]=1;
        vp.push_back({i-r,j-c});
        
       dfs(i-1,j,grid,vis,vp,r,c);
       dfs(i+1,j,grid,vis,vp,r,c);
       dfs(i,j-1,grid,vis,vp,r,c);
       dfs(i,j+1,grid,vis,vp,r,c);
       
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        
        //Can use set data strucute
        
        //Order Matters
        
            
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n,vector<int> (m,0));
        set<vector<pair<int,int>>> st;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {   
                if(grid[i][j] && !vis[i][j])
                {
                        vector<pair<int,int>> vp;
                        dfs(i,j,grid,vis,vp,i,j);
                        st.insert(vp);
                }
            }
        }
        
        return st.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends