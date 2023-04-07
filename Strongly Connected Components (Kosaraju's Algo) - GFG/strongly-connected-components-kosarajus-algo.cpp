//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{   
    private:
    void dfs(int i,vector<vector<int>>& adj,vector<int>& vis,stack<int>& st)
    {
        vis[i]=1;
        for(auto& ele: adj[i])
        {
            if(!vis[ele])
            dfs(ele,adj,vis,st);
            
        }
        
        st.push(i);
    }
    
    private: 
    void dfs3(int i,vector<int> adj[],vector<int>& vis)
    {
         vis[i]=1;
        for(auto& ele: adj[i])
        {   
            if(!vis[ele])
            dfs3(ele,adj,vis);
            
        }
    }
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //s1
        vector<int> vis(V,0);
        stack<int> st;
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
                dfs(i,adj,vis,st);
        }
        
        vector<int> adjT[V];
        //s2 reverse
        for(int i=0;i<V;i++)
        {   
            vis[i]=0;
            for(auto& ele: adj[i])
            {
                adjT[ele].push_back(i);
            }
        }
        int scc=0;
        
       while(!st.empty())
        {       
            int z=st.top();
            st.pop();
            if(!vis[z])
            {
                dfs3(z,adjT,vis);
                scc++;
            }
        }
        return scc;
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

    	vector<vector<int>> adj(V);

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