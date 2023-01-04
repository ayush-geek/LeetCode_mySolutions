//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
    
        
        queue<pair<int,int>> q;
        
        q.push({0,start});
        
        vector<int> dist(100000,INT_MAX);
        
        dist[start]=0;
        
        int m=100000;
        
        while(!q.empty())
        {
            int node=q.front().second;
            int steps=q.front().first;
            
            q.pop();
            
            for(auto it: arr)
            {
                int num=(it*node)%m;
                
                if(steps+1<dist[num])
                {
                    dist[num]=steps+1;
                    
                    if(num==end)
                        return dist[num];
                    q.push({dist[num],num});
                }
            }
            
        }
        
        
        return -1;
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