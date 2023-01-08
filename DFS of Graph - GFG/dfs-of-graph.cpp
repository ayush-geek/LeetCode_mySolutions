//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    
  private: 
  
  void dfs(int i,int V,vector<int> adj[],vector<int>& vis,vector<int>& res)
  {
      if(i<0 || i>=V || vis[i]==1)
        return ;
        
        vis[i]=1;
        res.push_back(i);
        
        for(auto ele: adj[i])
        {
            dfs(ele,V,adj,vis,res);
        }
  }
    
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        
        vector<int> vis(V,0);
        
        vector<int> res;
        dfs(0,V ,adj,vis,res);
        
        return res;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends