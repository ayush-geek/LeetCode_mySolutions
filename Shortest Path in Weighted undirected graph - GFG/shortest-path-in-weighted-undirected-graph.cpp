//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        
        vector<pair<int,int>> adj[n+1];
        
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        
        vector<int> dist(n+1,INT_MAX);
        
        vector<int> hash(n+1,0);
        
        for(int i=0;i<=n;i++)
            hash[i]=i;
            
            
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        
        pq.push({0,1});
        dist[1]=0;
        
        
        while(!pq.empty())
        {
            int d=pq.top().first;
            int e=pq.top().second;
            pq.pop();
            
            for(auto it: adj[e])
            {
                int v=it.first;
                int wt=it.second;
                
               if(d+wt<dist[v])
               {
                   dist[v]=d+wt;
                   pq.push({dist[v],v});
                   hash[v]=e;
               }
               
            }
            
        }
        
        int z=n;
        vector<int> res;
        
        res.push_back(z);
        
        while(hash[z]!=z)
        {
            z=hash[z];
            res.push_back(z);
            
        }
        
        reverse(res.begin(),res.end());
        
        if(res.size()==1)
            return {-1};
        return res;        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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