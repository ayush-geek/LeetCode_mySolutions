//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DSU{
    public:
    vector<int> size,parent;
    
    DSU(int n)
    {
        size.resize(n+1,1);
        parent.resize(n+1);
        iota(parent.begin(),parent.end(),0);
    }
    
    int findUpar(int nd)
    {
        if(parent[nd]==nd)
            return nd;
        return parent[nd]=findUpar(parent[nd]);
    }
    
    bool unionBySize(int u,int v)
    {
        int pu=findUpar(u);
        int pv=findUpar(v);
        
        if(pu==pv)
            return false;
        if(size[pu]<size[pv])
        {
            size[pv]+=size[pu];
            parent[pu]=pv;
        }
        else
        {
            size[pu]+=size[pv];
            parent[pv]=pu;
        }
        return true;
        
    }
};


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //sort the edge by w8
        int ans=0;
        DSU ds(V);
        vector<vector<int>> v;
        
        for(int i=0;i<V;i++)
        {
            for(auto& ele: adj[i])
            {
                v.push_back({ele[1],i,ele[0]});
            }
        }
        
        sort(v.begin(),v.end());
        
        for(int i=0;i<v.size();i++)
        {
            int a=v[i][1];
            int b=v[i][2];
            int w=v[i][0];
            if(ds.unionBySize(a,b))
            {
                ans+=w;
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