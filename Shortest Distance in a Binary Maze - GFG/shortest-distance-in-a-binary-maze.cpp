//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        
        if(source==destination)
            return 0;
        
        vector<vector<int>> vis(n,vector<int> (m,0));
        
        queue<pair<pair<int,int>,int>> q;
        
        q.push({source,0});
        vis[source.first][source.second]=1;
        int ans=INT_MAX;
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int d=q.front().second;
            q.pop();
           
                int dr[]={-1,0,1,0};
                int dc[]={0,-1,0,1};
                
                
                for(int i=0;i<4;i++)
                {
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] && !vis[nr][nc])
                    {
                        
                        vis[nr][nc]=1;
                        
                        q.push({{nr,nc},d+1});
                        
                        
                        if(nr==destination.first && nc==destination.second)
                            {
                                ans=min(ans,d+1);
                            }                        
                        
                    }
                }
            
        }
        
        if(ans==INT_MAX)
            return -1;
        
        return ans;
        
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends