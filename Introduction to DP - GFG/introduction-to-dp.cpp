//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
        vector<long long> dp;
  public:
    int mod=1e9+7;
    
    Solution()
    {
        dp.resize(1001,-1);
        
    }
    long long int topDown(int n) {
        // code here
        if(n<=1)
            return n;
        if(dp[n]!=-1)
            return dp[n];
            
        
        return dp[n]=(1ll*topDown(n-1)+1ll*topDown(n-2))%mod;
    }
    long long int bottomUp(int n) {
      
        dp.resize(n+1,0);
        
            dp[0]=0;
            dp[1]=1;
            
            for(int i=2;i<=n;i++)
            {
                dp[i]=(dp[i-1]+dp[i-2])%mod;
            }
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
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