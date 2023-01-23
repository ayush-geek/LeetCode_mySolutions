//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(int i,vector<int>& vis,vector<int>& path,vector<int> adj[])
    {
        vis[i]=1;
        path[i]=1;
        
        
        for(auto ele: adj[i])
            {
                if(!vis[ele])
                    {
                        if(dfs(ele,vis,path,adj)==true)
                            return true;
                    }
                else if(path[ele])
                    return true;
            }
            
        path[i]=0;
        return false;
    }
    
    bool isCyclic(int v, vector<int> adj[]) {
            
        vector<int> vis(v,0);
        vector<int> path(v,0);
        
        
        for(int i=0;i<v;i++)
        {
            if(!vis[i])
                {
                    if(dfs(i,vis,path,adj)==true)
                        return true;
                }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends