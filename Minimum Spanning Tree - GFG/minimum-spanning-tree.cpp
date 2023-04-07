//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int sm=0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        //{wt,node}
        pq.push({0,0});
        vector<int> vis(V,0);

        while(!pq.empty())
        {
            auto nd=pq.top();
            pq.pop();
            
            if(vis[nd.second]==1)
                continue;
             sm+=nd.first;
            vis[nd.second]=1;
           
            for(auto& ele: adj[nd.second])
            {
               // cout<<ele[0]<<" "<<ele[1]<<endl;
                if(!vis[ele[0]])
                    {
                        pq.push({ele[1],ele[0]});
                    }
            }
        }
        return sm;
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