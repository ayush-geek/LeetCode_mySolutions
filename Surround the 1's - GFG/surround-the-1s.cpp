//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int>>& grid) {
        // Code here
        
        int ans=0;
        
        int n=grid.size();
        int m=grid[0].size();
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                //chk 8 nhrs
                    int ct=0;
                    if(j-1>=0 && grid[i][j-1]==0)
                        ct++;
                    if(j+1<m && grid[i][j+1]==0)
                        ct++;
                    if(i-1>=0 && grid[i-1][j]==0)
                        ct++;
                    if(i+1<n && grid[i+1][j]==0)
                        ct++;
                        
                    if(i-1>=0 && j-1>=0 && grid[i-1][j-1]==0)
                        ct++;
                    
                    if(i-1>=0 && j+1<m && grid[i-1][j+1]==0)
                        ct++;
                    
                      if(i+1<n && j-1>=0 && grid[i+1][j-1]==0)
                        ct++;
                    
                    if(i+1<n && j+1<m &&  grid[i+1][j+1]==0)
                        ct++;
                        
                  //  cout<<ct<<endl;
                    if(ct!=0 && ct%2==0)
                        ans++;
                    
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends