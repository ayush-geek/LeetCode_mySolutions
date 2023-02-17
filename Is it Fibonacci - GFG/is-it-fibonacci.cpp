//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int k, vector<long long> GeekNum) {
        // code here
        long long z=accumulate(GeekNum.begin(),GeekNum.end(),0ll);
        
        for(int i=k;i<=N;i++)
        {
            GeekNum.push_back(z);
            z+=z-GeekNum[i-k];
        }
        return GeekNum[N-1];
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends