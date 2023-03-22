//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  
  int ans(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp)
  {
      int n=grid.size();
      int m=grid[0].size();
      
      
      
      if(j1<0 || j2<0 || j1>=m || j2>=m)
      {
          return -1e9;
      }
      
      if(dp[i][j1][j2]!=-1)
        return dp[i][j1][j2];
      if(i==n-1)
      {
          if(j1==j2)
            return dp[i][j1][j2]=grid[i][j1];
            else
                return dp[i][j1][j2]=grid[i][j1]+grid[i][j2];
      }
      
      int mx=0;
      for(int k=-1;k<=1;k++)
      {
          for(int l=-1;l<=1;l++)
          {
              int nc1=j1+k;
              int nc2=j2+l;
              if(j1==j2)
              mx=max(mx,grid[i][j1]+ans(i+1,nc1,nc2,grid,dp) );
              else
                 mx=max(mx,grid[i][j1]+grid[i][j2]+ans(i+1,nc1,nc2,grid,dp) );
          }
      }
      return dp[i][j1][j2]=mx;
      
      
  }
  
  
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        // int n=grid.size();
    //   int m=grid[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (m+1,vector<int> (m+1,-1)));
        
        return ans(0,0,m-1,grid,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends