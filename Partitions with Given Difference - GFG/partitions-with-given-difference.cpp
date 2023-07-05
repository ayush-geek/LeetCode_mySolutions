//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod=1e9+7;
	int perfectSum(vector<int>& nums, int n, int sum)
	{
        // Your code goes here
	  int tgt=sum;
	 vector<vector<int>> dp(n+1,vector<int> (tgt+1,0));

    // for(int i=0;i<n;i++)
    // {
    //     dp[i][0]=1;
    // }
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=tgt;j++)
            {
                if(nums[i-1]<=j)
                    dp[i][j]=dp[i-1][j-nums[i-1]];
                
                dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
               
            }
          
        }
	  
	    return dp[n][sum];
	}
    
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        
        int s=accumulate(arr.begin(),arr.end(),0);
        
        int tgt=(d+s)/2;
        
        if((d+s)%2!=0)
            return 0;
        // cout<<tgt<<endl;
    return perfectSum(arr,n,tgt);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends