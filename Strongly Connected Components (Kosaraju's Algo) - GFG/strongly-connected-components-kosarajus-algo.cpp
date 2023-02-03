//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    
    
    void dfs(int i,vector<int>& vis,vector<int> adj[],stack<int>& st)
    {
        vis[i]=1;
        
        for(auto it: adj[i])
        {
            if(!vis[it])
                dfs(it,vis,adj,st);
        }
        st.push(i);
    }    
    
    
    void dfs2(int i,vector<int>& vis,vector<int> adj[])
    {
        vis[i]=1;
        
        for(auto it: adj[i])
        {
            if(!vis[it])
                dfs2(it,vis,adj);
        }
       
    }    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //Sort
      vector<int> vis(V,0);
      stack<int> st;
      for(int i=0;i<V;i++)
      {
          if(!vis[i])
            dfs(i,vis,adj,st);
      }
      
      
      //rEVERSE
      
      vector<int> adjT[V];
      for(int i=0;i<V;i++)
      { vis[i]=0;
          for(int j=0;j<adj[i].size();j++)
          {
              adjT[adj[i][j]].push_back(i);
          }
      }
      int ct=0;
      while(!st.empty())
      {
          int nd=st.top();
          st.pop();
          
          if(!vis[nd])
          {
              dfs2(nd,vis,adjT);
              ct++;
          }
      }
      return ct;
      
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