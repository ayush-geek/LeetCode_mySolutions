//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
      
      //min operations
    int mod=1e5;
    queue<pair<int,int>> pq;
      pq.push({0,start});
      vector<int> dis(100000,1e9);
      dis[0]=0;
      while(!pq.empty())
      {
          auto node=pq.front();
          int d=abs(node.first);
          int nd=node.second;
          pq.pop();
        
            if (nd == end)
                return d ;
          
          for(auto& ele: arr)
          {
              long long z=(ele*nd)%mod;
              
              if(dis[z]>d+1)
              {
                  dis[z]=d+1;
                    pq.push({-1*(d+1),z});
                  
              }
            
          }
          
      }
      if(dis[end]==1e9) 
        return -1;
      return dis[end];
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends