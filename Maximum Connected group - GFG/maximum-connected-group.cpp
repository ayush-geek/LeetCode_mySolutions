//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class DSU
{
public: 
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
    int MaxConnection(vector<vector<int>>& grid) {
       
       
        int n=grid.size();
        
        DSU ds(n*n);
        
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                    {
                        
                        for(int k=0;k<4;k++)
                        {
                            int nr=i+dr[k];
                            int nc=j+dc[k];
                            
                            
                            if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1)
                            {
                                ds.unionBySize(i*n+j,nr*n+nc);
                            }
                        }
                    }
            }
        }
        
        int mx=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                {
                    set<int>st;
                    if(grid[i][j]==0)
                    {
                         for(int k=0;k<4;k++)
                        {
                            int nr=i+dr[k];
                            int nc=j+dc[k];
                            
                            
                            if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1)
                            {
                                st.insert(ds.findUPar(nr*n+nc));
                            }
                        }
                    }
                    
                    
                    int ans=0;
                    for(auto ele: st)
                    {
                        ans+=ds.size[ele];
                    }
                    ans++;
                    
                    mx=max(mx,ans);
                    
                    mx=max(mx,ds.size[i*n+j]);
                }
        }
        
return mx;
        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends