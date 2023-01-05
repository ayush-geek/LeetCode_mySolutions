//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

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



class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        
        int n=V;
        DSU ds(V);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j &&  adj[i][j]==1)
                {
                    int pi=ds.findUPar(i);
                    int pj=ds.findUPar(j);
                    
                    if(pi!=pj)
                    {
                        ds.unionBySize(i,j);
                    }
                }
            }
        }
       int ans=0; 
        
        for(int i=0;i<V;i++)
        {
            if(ds.findUPar(i)==i)
                ans++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends