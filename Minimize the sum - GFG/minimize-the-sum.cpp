//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        
        
        priority_queue<int> pq;
        
        for(int i=0;i<N;i++)
        {
            pq.push((-1)*arr[i]);
        }
        
        
        int sm=0;
        while(pq.size()>1)
        {
            int z1=pq.top();
            pq.pop();
            int z2=pq.top();
            pq.pop();
            sm+=z1+z2;
            pq.push(z1+z2);
        }
        
        return abs(sm);
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends