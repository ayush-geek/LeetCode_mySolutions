//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    int timer=1;
private:
void dfs(int i,int par,vector<int>& vis,vector<int> adj[],vector<int>& mark,int low[],int tin[])
{
    vis[i]=1;
    low[i]=tin[i]=timer;
    timer++;
    int child=0;
    for(auto& ele: adj[i])
    {
        
        
        if(ele==par)
            continue;
        
        if(!vis[ele])
        {
                   dfs(ele,i,vis,adj,mark,low,tin);
                  low[i]=min(low[ele],low[i]);
                  
                //poiny
                if(low[ele]>=tin[i] && par!=-1)
                    mark[i]=1;
            child++;
        }
        else
        {
               low[i]=min(tin[ele],low[i]);
        }
        
    }
    
    if(child>1 && par==-1)
        mark[i]=1;
    
}
    
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        
        int tin[V];
        int low[V];
        vector<int> mark(V,0);
        vector<int> vis(V,0);
        vector<int> res;
        
        dfs(0,-1,vis,adj,mark,low,tin);
        
        
        for(int i=0;i<V;i++)
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