//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class dsu
{
public:
	vector<int> rank,parent,size;
	dsu(int n){
		rank.resize(n+1,0);
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

	void unionByRank(int u,int v)
	{	
		int up_u=findUpar(u);
		int up_v=findUpar(v);
		if(up_u == up_v)
			return ;

		if(rank[up_u]<rank[up_v])
			parent[up_u]=up_v;
		else if(rank[up_v]<rank[up_u])
			parent[up_v]=up_u;
		else
		{
			parent[up_v]=up_u;
			rank[up_u]++;
		}

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

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<int> ans;
        dsu ds(n*m);
        
        vector<vector<int>> vis(n,vector<int> (m,0));
        int ct=0;
        
        
        for(auto it: operators)
        {
            int r=it[0];
            int c=it[1];
            
            if(vis[r][c])
            {
               
                ans.push_back(ct);
                continue;
            }
            
            vis[r][c]=1;
            ct++;
            
            int dr[]={-1,0,1,0};
            int dc[]={0,-1,0,1};
            
            for(int i=0;i<4;i++)
            {
                int nr=r+dr[i];
                int nc=c+dc[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc])
                {
                    int n_n=r*m+c;
                    int nn_n=nr*m+nc;
                    
                    if(ds.findUpar(n_n)!=ds.findUpar(nn_n))
                    {
                        ct--;
                        ds.unionBySize(n_n,nn_n);
                    }
                }
            }
            
            ans.push_back(ct);
        }
        
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends