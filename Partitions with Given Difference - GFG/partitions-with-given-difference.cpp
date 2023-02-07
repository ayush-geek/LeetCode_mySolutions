//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod= 1e9 + 7;
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        
      int sum=accumulate(arr.begin(),arr.end(),0);
	    vector<vector<int>> dp(n+1,vector<int>  (sum+1,0));
            
            //for(int i=0;i<=n;i++)
                dp[0][0]=1;
                
            
            for(int i=1;i<=n;i++)
            {
                for(int j=0;j<=sum;j++)
                {
                    if(j>=arr[i-1])
                        dp[i][j]=dp[i-1][j-arr[i-1]];
                    
                    dp[i][j]=(dp[i][j] + dp[i-1][j])%mod;
                }
            }
           
            int ans=0;
           for(int j=0;j<=sum;j++)
           {
               if(dp[n][j])
               {
                   int s1=j;
                int s2=sum-j;
                
                if(s1-s2==d)
                {
                    ans+=dp[n][j];
                }

               }
           }
           
          
                return ans;
        
   
        
    
        
      
      
        
        
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