//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
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

class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        
        int mr=0;
        int mc=0;
        
        for(int i=0;i<stones.size();i++)
        {
            mr=max(mr,stones[i][0]);
            mc=max(mc,stones[i][1]);
        }
    
        
        DSU ds(mr+mc+1);
        
        unordered_map<int,int> mp;
        
        for(auto it: stones)
        {
            int nr=it[0];
            int nc=it[1]+mr+1;
            
            ds.unionBySize(nr,nc);
            mp[nr]=1;
            mp[nc]=1;
        }
        
        int c=0;
        for(auto it: mp)
        {
            if(ds.findUPar(it.first)==it.first)
                c++;
        }
        
        return n-c;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends