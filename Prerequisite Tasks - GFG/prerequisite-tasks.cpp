//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    
	    
	    vector<int> adj[N];
	    
	    vector<int> indeg(N,0);
	    
	    for(int i=0;i<prerequisites.size();i++)
	    {
	        adj[prerequisites[i].second].push_back(prerequisites[i].first);
	        
	        indeg[prerequisites[i].first]++;
	        
	        
	    }
	    
	    
	    queue<int> q;
	    int ct=0;
	    
	    for(int i=0;i<N;i++)
	    {
	        if(indeg[i]==0)
	        {
	            ct++;
	            q.push(i);
	        }
	    }
	    
	   while(!q.empty())
	   {
	       int nd=q.front();
	       
	       q.pop();
	       
	       for(auto ele: adj[nd])
	       {
	           indeg[ele]--;
	           
	           if(indeg[ele]==0)
	            {
	                q.push(ele);
	                ct++;
	            }
	       }
	   }
	   
	   if(ct==N)
	    return true;
	    
	    return false;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends