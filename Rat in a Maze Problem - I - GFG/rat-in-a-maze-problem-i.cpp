//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    
    
    
    private:
    
    void solve(int i,int j,vector<vector<int>>& m,string& tmp,vector<vector<int>>& vis)
    {
        int n=m.size();
        
        if(i<0 || i>=n || j<0 || j>=n | vis[i][j]==1|| m[i][j]==0 )
            return ;
            
        
        if(i==n-1 && j==n-1)
        {
            res.push_back(tmp);
            return ;
        }
        
        vis[i][j]=1;
        
        tmp.push_back('U');
        solve(i-1,j,m,tmp,vis);
         tmp.pop_back();
        
        tmp.push_back('L');
        solve(i,j-1,m,tmp,vis);
        tmp.pop_back();
        
        tmp.push_back('R');
        solve(i,j+1,m,tmp,vis);
         tmp.pop_back();
            
          tmp.push_back('D');
        solve(i+1,j,m,tmp,vis);
          tmp.pop_back();
        
        vis[i][j]=0;
    }
    
    
    public:
    
    vector<string> res;
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
      
        string tmp="";
        vector<vector<int>> vis(n,vector<int> (n,0));
        
        solve(0,0,m,tmp,vis);
      
      return res;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends