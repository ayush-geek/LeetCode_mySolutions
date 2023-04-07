//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DSU{
     public:
  vector<int> parent,size;
  
 
    DSU(int n)
    {
        parent.resize(n+1);
        size.resize(n+1,1);
        iota(parent.begin(),parent.end(),0);
    }
    
    
    int findUpar(int x)
    {
        if(parent[x]==x)
            return x;
        return parent[x]=findUpar(parent[x]);
    }
    
    
    void unionBySize(int u,int v)
    {
        int pu=findUpar(u);
        int pv=findUpar(v);
        
        if(pu==pv)
            return ;
        
        if(size[pu]>size[pv])
        {
           
            size[pu]+=size[pv];
             parent[pv]=pu;
        }
        else
        {
             size[pv]+=size[pu];
             parent[pu]=pv;
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        DSU ds(V);
        int sm=0;
        vector<vector<int>> edges;
        
        
        for(int i=0;i<V;i++)
        {
            for(auto& ele: adj[i])
            {
                int u=i;
                int v=ele[0];
                int w=ele[1];
                
                edges.push_back({w,u,v});
            }
        }
        
        
        sort(edges.begin(),edges.end());
        
        for(auto& ele: edges)
        {
              int u=ele[1];
              int v=ele[2];
              int w=ele[0];
              
              int pu=ds.findUpar(u);
              int pv=ds.findUpar(v);
            
          
              if(pu!=pv)
              {
                  ds.unionBySize(u,v);
                  sm+=w;
                  //cout<<sm<<endl;
              }
                
        }
        return sm;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends