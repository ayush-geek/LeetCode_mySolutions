//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int ct=0;
    bool dfs(int nd,vector<int> adj[],vector<int>& vis)
    {   
        
        vis[nd]=1;
        bool select=false;
        for(auto ele: adj[nd])
        {
            if(!vis[ele])
            {
                bool ss=dfs(ele,adj,vis);
                
                select=select| (!ss);
            }
        }
        if(select)
         ct++;
         return select;
    }
  
    int countVertex(int N, vector<vector<int>>edges){
        // code here
        
        vector<int> adj[N+1];
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> vis(N+1,0);
        dfs(1,adj,vis);
        return ct;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends