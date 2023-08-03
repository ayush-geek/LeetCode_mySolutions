//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int n,int M, vector<vector<int>>& edges){
        
        //dijkstra
        vector<pair<int,int>> adj[n];
        
        for(auto& ele: edges)
        {
            int a=ele[0];
            int b=ele[1];
            int w=ele[2];
            adj[a].push_back({b,w});
        }
        vector<int> dis(n,1e9);
        
        priority_queue< pair<int,int> , 
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;
        
        pq.push({0,0});
        dis[0]=0;
        
        while(!pq.empty())
        {
            auto node=pq.top();
            pq.pop();
            auto d=node.first;
            auto nd=node.second;
            
            for(auto& ele: adj[nd])
            {
                int adjnode=ele.first;
                int w=ele.second;
                
                
                if(d+w<dis[adjnode])
                {
                    dis[adjnode]=d+w;
                    pq.push({dis[adjnode],adjnode});
                }
            }
        }
        
        
        for(int i=0;i<n;i++)
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