//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class dsu
{
public:
	vector<int> parent,size;
	dsu(int n){
	
		parent.resize(n+1);
		size.resize(n+1,1);

		for(int i=0;i<=n;i++)
			parent[i]=i;
	}

	int findUpar(int node)
	{
		if(node==parent[node])
			return node;

		return parent[node]=findUpar(parent[node]);

	}

	

	void unionBySize(int u,int v)
	{	
		int up_u=findUpar(u);
		int up_v=findUpar(v);
		if(up_u == up_v)
			return ;

		if(size[up_u]<size[up_v]){
			parent[up_u]=up_v;
			size[up_v]+=size[up_u];
		}
		
		else
		{
			parent[up_v]=up_u;
			size[up_u]+=size[up_v];
		}

	}
	
	
};


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        dsu ds(V);
        vector<pair<int,pair<int,int>>> edges;
        
        for(int i=0;i<V;i++)
        {
            for(auto ele: adj[i])
            {
                edges.push_back({ele[1],{ele[0],i}});
            }
        }
        
        sort(edges.begin(),edges.end());
        
        int ans=0;
        
        for(auto ele: edges)
        {
            int wt=ele.first;
            int u=ele.second.first;
            int v=ele.second.second;
            
            
            if(ds.findUpar(u)!=ds.findUpar(v))
            {
                ds.unionBySize(u,v);
                ans+=wt;
            }
        }
        return ans;
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