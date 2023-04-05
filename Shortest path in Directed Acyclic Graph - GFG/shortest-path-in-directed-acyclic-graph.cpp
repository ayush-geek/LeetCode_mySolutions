//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        
        vector<pair<int,int>> adj[N];
        
        for(auto&ele: edges)
        {
            adj[ele[0]].push_back({ele[1],ele[2]});
        }
        
        vector<int> dis(N,1e9);
        queue<int> q;
        q.push(0);
        dis[0]=0;
        while(!q.empty())
        {
            int nd=q.front();
            q.pop();
            
            for(auto&ele: adj[nd])
            {   
                int w=ele.second;
                int node=ele.first;
                if(dis[nd]+w<dis[node])
                {
                    //upadte
                    dis[node]=w+dis[nd];
                    q.push(node);
                }
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