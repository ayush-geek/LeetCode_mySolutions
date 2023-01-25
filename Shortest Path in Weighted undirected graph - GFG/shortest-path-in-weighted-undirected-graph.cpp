//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        
        vector<pair<int,int>> adj[n+1];
        
        for(int i=0;i<m;i++)
        {
            int a=edges[i][0];
            int b=edges[i][1];
            int c=edges[i][2];
            
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        
        vector<int> dis(n+1,INT_MAX);
        vector<int> hash(n+1,0);
        hash[1]=1;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dis[1]=0;
        pq.push({0,1});
        
        while(!pq.empty())
        {
            auto it =pq.top();
            int nd=it.second;
            int d=it.first;
            pq.pop();
            
            for(auto ele: adj[nd])
            {
                int ne=ele.first;
                int w=ele.second;
                
                
                if(dis[ne]>d+w)
                {
                    dis[ne]=d+w;
                    hash[ne]=nd;
                    pq.push({dis[ne],ne});
                }
            }
        }
        
        vector<int> res;
        if(dis[n]==INT_MAX)
            return {-1};
        
        res.push_back(n);
        int k=n;
        while(hash[k]!=k)
        {
            k=hash[k];
            res.push_back(k);
        }
        
        reverse(res.begin(),res.end());
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