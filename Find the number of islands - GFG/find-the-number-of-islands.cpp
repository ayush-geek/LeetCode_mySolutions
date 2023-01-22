//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
    void dfs(int r,int c,vector<vector<char>>& grid,vector<vector<int>>& vis)
    {
         int n=grid.size();
        int m=grid[0].size();
        
       
        vis[r][c]=1;
        
      for(int i=-1;i<=1;i++)
      {
          for(int j=-1;j<=1;j++)
          {
              int nr=r+i;
              int nc=c+j;
              
              if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]=='1')
              {
                  dfs(nr,nc,grid,vis);
              }
          }
      }
      
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        //bfs 
        
        
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    dfs(i,j,grid,vis);
                    ans++;
                    
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends