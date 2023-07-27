//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

typedef pair<int,pair<int,int>> ppi;
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {    
    
  
    int n=V;

vector<int> vis(n,0);

  int ans=0;

  //wt node parent
  priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
  pq.push({0,{0,-1}});
//   vis[0]=1;

  while(!pq.empty())
  { 
    auto w=pq.top().first;
    auto node=pq.top().second.first;
    auto par=pq.top().second.second;
    pq.pop();

    if(vis[node])
      continue;
      vis[node]=1;
      ans+=w;

      for(auto& ele: adj[node])
      { 
          //cout<<node<<" "<<ele[0]<<endl;
        if(!vis[ele[0]])
        {
          pq.push({ele[1],{ele[0],node}});
        }
          
      }

  }
  return ans;

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