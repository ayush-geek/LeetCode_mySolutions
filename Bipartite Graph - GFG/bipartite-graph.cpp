//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool solve(int i,int col,int V,vector<int> adj[],vector<int>& vis)
    {
        vis[i]=col;
        
        
        for(auto& ele: adj[i])
        {
            if(vis[ele]==0)
                {
                    if(solve(ele,-1*col,V,adj,vis))
                        return true;
                }
            else if(vis[ele]==vis[i])
                return true;
        }
        return false;
    }
    

	bool isBipartite(int V, vector<int>adj[]){
	   
	   vector<int> vis(V,0);
	   for(int i=0;i<V;i++)
	   {
	       if(!vis[i] && solve(i,1,V,adj,vis))
	            return false;
	   }
	  
	  return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends