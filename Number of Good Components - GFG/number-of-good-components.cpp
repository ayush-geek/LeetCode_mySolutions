//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void dfs(int i,vector<vector<int>>& adj,vector<int>&  tmp,vector<int>& vis)
    {
        
        vis[i]=1;
        tmp.push_back(i);
        
        for(auto& ele: adj[i])
            {
                if(!vis[ele])
                    dfs(ele,adj,tmp,vis);
            }
        
    }
  
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
       int n=V;
       vector<int> vis(n+1,0);
       int ct=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
                {   
                    vector<int> tmp;
                    dfs(i,adj,tmp,vis);
                    
                    int tp=0;
                    for(auto& ele: tmp)
                    {
                        tp+=adj[ele].size();
                    }
                    int f=tmp.size();
                    //cout<<f<<" "<<tp<<" "<<i<<endl;
                    if(tp/2==f*(f-1)/2)
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
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends