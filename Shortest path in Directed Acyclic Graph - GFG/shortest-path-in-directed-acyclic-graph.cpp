//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
       
       vector<int> dis(N,1e9);
       
       dis[0]=0;
        
        vector<pair<int,int>> adj[N];
        vector<int> indeg(N,0);
        for(int i=0;i<M;i++)
        {
            int a=edges[i][0];
            int b=edges[i][1];
            int w=edges[i][2];
            
            adj[a].push_back({b,w});
            indeg[b]++;
            
        }
        
       queue<int> q;
       vector<int> res;
   
        
    for(int i=0;i<N;i++)
    {
        if(indeg[i]==0)
            q.push(i);
    }
        // indeg[i]=0;
        
        while(!q.empty())
        {
            int nd=q.front();
            res.push_back(nd);
            q.pop();
            
            
            for(auto ele: adj[nd])
            {
                indeg[ele.first]--;
                if(indeg[ele.first]==0)
                    q.push(ele.first);
            }
        }
        
  
        
        for(int i=0;i<res.size();i++)
        {   
            int nd=res[i];
            for(auto ele: adj[nd])
            {
                int v=ele.first;
                int wt=ele.second;
                
                if(dis[nd]+wt<dis[v])
                    dis[v]=dis[nd]+wt;
            }
        }
        
        for(int i=0;i<N;i++)
        {
            if(dis[i]==1e9)
                dis[i]=-1;
        }
       
       return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends