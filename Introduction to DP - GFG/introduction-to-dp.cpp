//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
vector<long long> dp(100001,-1);
long long mod=1e9+7;
class Solution {
  public:
    long long int topDown(int n) {
        
        long long prev2=0;
        long long prev=1;
        
        for(int i=2;i<=n;i++)
        {
            long long cur=(prev2+prev)%mod;
            prev2=prev;
            prev=cur;
        }
       // cout<<prev<<endl;
        return prev;
        
        
    }
    long long int bottomUp(int n) {
        if(n==1)
            return 1;
        if(n==0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        long long z1=bottomUp(n-1);
        long long z2=bottomUp(n-2);
        
        return dp[n]=(z1+z2)%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 100001; i++) dp[i] = -1;
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends