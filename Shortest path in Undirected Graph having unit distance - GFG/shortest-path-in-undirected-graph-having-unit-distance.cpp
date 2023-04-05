//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
       //bfs
       vector<int> dis(N,1e9);
       vector<int>adj[N];
       
       for(auto& ele: edges)
       {
           adj[ele[0]].push_back(ele[1]);
           adj[ele[1]].push_back(ele[0]);
       }
       queue<int> q;
       q.push(src);
       dis[src]=0;
       
       while(!q.empty())
       {
           int nd=q.front();
           q.pop();
           
           for(auto&ele: adj[nd])
           {
               if(dis[nd]+1<dis[ele])
               {
                   dis[ele]=1+dis[nd];
                   q.push(ele);
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
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends