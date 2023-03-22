//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimizeCost(vector<int>& nums, int n, int k) {
        // Code here
        
        vector<int> dp(n+1,1e9);
        
        
        //Base Condition
       dp[0]=0;
        
        //Solve the PRoblem Now
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=max(i-k,0);j--)
            {
                int z1=abs(nums[i]-nums[j])+dp[j];
                
                dp[i]=min(dp[i],z1);
                
            }
        }
        
        return dp[n-1];
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends