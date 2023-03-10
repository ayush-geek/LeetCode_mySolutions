//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        
        vector<int> dis(V,INT_MAX);
        
        
        set<pair<int,int>> st;
        st.insert({0,S});
        dis[S]=0;
        while(!st.empty())
        {
            auto it=*(st.begin());
            int d=it.first;
            int nd=it.second;
            st.erase(it);
            
            for(auto ele: adj[nd])
            {
                int ne=ele[0];
                int w=ele[1];
                
                if(d+w<dis[ne])
                {
                    if(dis[ne]!=INT_MAX)
                    {
                        st.erase({dis[ne],ne});
                        
                    }
                    dis[ne]=d+w;
                    st.insert({dis[ne],ne});
                }
            }
        }
        
        // //Min pq
        
        // priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        // dis[S]=0;
        // pq.push({0,S});
        
        // while(!pq.empty())
        // {
        //     auto it=pq.top();
        //     int nd=it.second;
        //     int d=it.first;
        //     pq.pop();
            
        //     for(auto ele: adj[nd])
        //     {
        //         int wt=ele[1];
        //         int ne=ele[0];
                
        //         if(dis[ne]>wt+d)
        //         {
        //             dis[ne]=d+wt;
        //             pq.push({dis[ne],ne});
        //         }
        //     }
        // }
        
        return dis;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends