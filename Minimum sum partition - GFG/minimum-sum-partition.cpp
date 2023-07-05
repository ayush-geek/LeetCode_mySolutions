//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int nums[], int n)  { 
	   int sm=accumulate(nums,nums+n,0);


    int tgt=sm/2;

    vector<vector<int>> dp(n+1,vector<int> (tgt+1,0));

    for(int i=0;i<n;i++)
    {
        dp[i][0]=1;
    }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=tgt;j++)
            {
                if(nums[i-1]<=j)
                    dp[i][j]=dp[i-1][j-nums[i-1]];
                
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
               
            }
          
        }
        
        int ans=sm;
        for(int j=1;j<=tgt;j++)
        {
            if(dp[n][j])
            {
                int d=abs((sm-j)-j);
                
                ans=min(ans,d);
            }
        }

       return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends