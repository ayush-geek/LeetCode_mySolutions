//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(int i,vector<int>& vis,vector<int> adj[])
    {
        vis[i]=2;
       
        
        
        for(auto ele: adj[i])
            {
                if(!vis[ele])
                    {
                        if(dfs(ele,vis,adj)==true)
                            return true;
                    }
                else if(vis[ele]==2)
                    return true;
            }
            
        vis[i]=1;
        return false;
    }
    
    bool isCyclic(int v, vector<int> adj[]) {
            
        vector<int> indeg(v,0);
	
	    vector<int> res;
	    
	    for(int i=0;i<v;i++)
	    {
	        for(auto ele: adj[i])
	        {
	            indeg[ele]++;
	        }
	    }
	    
	    queue<int> q;
	    
	    for(int i=0;i<v;i++)
	    {
	        if(indeg[i]==0)
	            q.push(i);
	    }
	  
	    while(!q.empty())
	    {
	        int nd=q.front();
	        res.push_back(nd);
	        q.pop();
	        
	        for(auto ele: adj[nd])
	        {
	            indeg[ele]--;
	            
	            if(indeg[ele]==0)
	                q.push(ele);
	        }
	    }
	  
	    if(res.size()==v)
	        return false ;
	       return true;
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