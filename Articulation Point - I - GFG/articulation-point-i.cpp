//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
 private:
 int timer=1;
 
 void dfs(int i,int parent, vector<int>&  vis,vector<int>& tin, vector<int>& low,vector<int>& mark,vector<int> adj[])
 {
     
     vis[i]=1;
     
     tin[i]=low[i]=timer;
     timer++;
     
     
     int child=0;
     for(auto it: adj[i])
    {
            if(it==parent)
                continue;
                
                if(!vis[it])
                {
                    dfs(it,i,vis,tin,low,mark,adj);
                    
                    low[i]=min(low[i],low[it]);
                
    
                child++;
            if(low[it]>=tin[i] && parent!=-1)
                mark[i]=1;
                }
            else
            {
                 low[i]=min(low[i],low[it]);
            }
    }
    
    if(child>1 && parent==-1)
        mark[i]=1;
 }
    
    
    
    
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        int n=V;
        vector<int> vis(n,0);
        vector<int>  mark(n,0);
        
        vector<int> tin(n,0);
        vector<int> low(n,0);
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                dfs(i,-1,vis,tin,low,mark,adj);
        }
        
        for(int i=0;i<n;i++)
        {
            if(mark[i]==1)
                res.push_back(i);
        }
        
        if(res.size()==0)
            return {-1};
        return res;
        
        
        
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