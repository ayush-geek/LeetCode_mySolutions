//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        //n-1 traversal u will get min distance
        //if again min distance 
        
        vector<int> dis(V,1e8);
        dis[S]=0;
        
        
        int z=V-1;
        while(z--)
        {
            for(auto& ele: edges)
            {
                int u=ele[0];
                int v=ele[1];
                int wt=ele[2];
                
                if(dis[u]+wt<dis[v])
                {
                    dis[v]=dis[u]+wt;
                }
            }
        }
        
        int fg=0;
        for(auto& ele: edges)
            {
                int u=ele[0];
                int v=ele[1];
                int wt=ele[2];
                
                if(dis[u]+wt<dis[v])
                {
                   fg=1;
                   break;
                }
            }
        
        
        if(fg==1)
            return {-1};
       
        return dis;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
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

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends