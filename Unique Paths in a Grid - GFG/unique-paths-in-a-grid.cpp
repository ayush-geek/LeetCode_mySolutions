//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int m=1e9+7;
    int solve(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &vis)
    {
        if(i<0 || j<0  || grid[i][j]==0)
            return 0;
        if(i==0 && j==0)
            return 1;
        if(vis[i][j]!=-1)
            return vis[i][j];
            
        int z1=solve(i-1,j,grid,vis);
    //    int z2=solve(i+1,j,grid,vis);
        int z3=solve(i,j-1,grid,vis);
       // int z4=solve(i,j+1,grid,vis);
        
        return vis[i][j]=(z1+z3)%m;
    }
  
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        
        vector<vector<int>> vis(n,vector<int> (m,-1));
        return solve(n-1,m-1,grid,vis);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends