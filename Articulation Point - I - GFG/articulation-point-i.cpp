//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  
 private: 
    int timer=0;

    void dfs(int nd,int par,vector<int> adj[],vector<int>& vis,vector<int>& tin,vector<int>& lin,
    vector<int>& mark)
    {
        vis[nd]=1;
        tin[nd]=lin[nd]=timer;
        timer++;

        int ch=0;
        for(auto it: adj[nd])
        {
            if(it==par)
                continue;
            else if(!vis[it])
            {
                dfs(it,nd,adj,vis,tin,lin,mark);
                 lin[nd]=min(lin[nd],lin[it]);

                 if(lin[it]>=tin[nd] && par!=-1)
                   mark[nd]=1;
                 ch++;
            }
            else
            {
                lin[nd]=min(lin[nd],tin[it]);
            }
        }
        
        if(ch>1 && par==-1)
            mark[nd]=1;
    }

 
  
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        int n=V;
        vector<int> vis(n,0);
         vector<int> mark(n,0);
       vector<int> tin(n,0);
       vector<int> lin(n,0);
      
      
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                dfs(i,-1,adj,vis,tin,lin,mark);
        }
        
        for(int i=0;i<n;i++)
        {
          if(mark[i])
                ans.push_back(i);
        }
        if(ans.empty())
            return {-1};
        return ans;
        
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
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends