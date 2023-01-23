//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        
        queue<pair<int,int>> q;
        
       
      
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(vis[i])
                continue;
        
        
         q.push({i,-1});
          vis[i]=1;
        
       while(!q.empty())
       {
           int nd=q.front().first;
            int par=q.front().second;
           q.pop();
           
           
           for(auto ele: adj[nd])
           {
               if(!vis[ele])
               {
                   vis[ele]=1;
                   q.push({ele,nd});
               }
               
               else if(ele!=par)
                    return true;
           }
           
           
       }
        }
        return false;
        
        
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends