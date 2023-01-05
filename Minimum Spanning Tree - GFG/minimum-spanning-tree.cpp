//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


 class DSU
{
private: 
    vector<int> rank, parent, size;
  
public:
    DSU(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);

        for(int i=0;i<=n;i++)
            parent[i]=i;
    };
   
    int findUPar(int u)
    {
        if(u==parent[u])
            return u;

        return parent[u]=findUPar(parent[u]);
    }

    void unionByRank(int u,int v)
    {
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);

        if(ulp_u==ulp_v)   
            return ;

        if(rank[ulp_u]<rank[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            //rank[ulp_v]++;
            
        }
        else  if(rank[ulp_u]>rank[ulp_v])
        {
            parent[ulp_v]=ulp_u;
            // rank[ulp_u]++;
        }
        else{
             parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }

    }


     void unionBySize(int u,int v)
    {
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);

        if(ulp_u==ulp_v)   
            return ;

        if(size[ulp_u]<=size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
            
        }
        else
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }

    }


};



class Solution
{
	
	
	
	
	
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	
	
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
     
        DSU  ds(V);
        
        
        vector<pair<int,pair<int,int>>> edges;
        
        
        for(int i=0;i<V;i++)
        {
        for(auto itr: adj[i])
        {
            int v=itr[0];
            int wt=itr[1];
           
            
            //cout<<wt<<endl;
            edges.push_back({wt,{i,v}});
            
            
            
        }
        }
        
        sort(edges.begin(),edges.end());
        
        int ans=0;
        for(auto it: edges)
        {
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            
            
            if(ds.findUPar(u)!=ds.findUPar(v))
            {
                //cout<<wt<<endl;
                ans+=wt;
                
                ds.unionBySize(u,v);
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