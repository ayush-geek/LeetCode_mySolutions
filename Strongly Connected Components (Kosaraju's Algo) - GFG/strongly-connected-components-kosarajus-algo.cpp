//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    
    private: 
    void dfs(int i,vector<int> adj[],vector<int>& vis,stack<int>& st)
    {
        vis[i]=1;
        
        for(auto it: adj[i])
        {
            if(!vis[it])
                dfs(it,adj,vis,st);
        }
        
        st.push(i);
    }
    
    private: 
    void dfs3(int i,vector<int> adj[],vector<int>& vis)
    {
        vis[i]=1;
        
        for(auto it: adj[i])
        {
            if(!vis[it])
                dfs3(it,adj,vis);
        }
        
        
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        
        vector<int> vis(V,0);
        stack<int> st;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
                dfs(i,adj,vis,st);
        }
        
        
        //Reverse
        vector<int> adjT[V];
        
        for(int i=0;i<V;i++)
        {   vis[i]=0;
            for(auto itr: adj[i])
            {
                adjT[itr].push_back(i);
            }
        }
        
        
       
        //DFS
        int ans=0;
        while(!st.empty())
        {
            int i=st.top();
            if(!vis[i]){
                dfs3(i,adjT,vis);
                ans++;
            }
            
            st.pop();
        }
        
       
        return ans;
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends