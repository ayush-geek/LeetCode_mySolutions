//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    
	    int sum=accumulate(arr,arr+n,0);
	    vector<vector<int>> dp(n+1,vector<int>  (sum+1,0));
            
            for(int i=0;i<=n;i++)
                dp[i][0]=1;
                
            
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=sum;j++)
                {
                    if(j>=arr[i-1])
                        dp[i][j]=dp[i-1][j-arr[i-1]];
                    
                    dp[i][j]=(dp[i][j]|| dp[i-1][j]);
                }
            }
           
           int diff=INT_MAX;
           for(int j=0;j<=sum;j++)
           {
               if(dp[n][j])
               {
                int other=sum-j;
                
                if(abs(other-j)<diff)
                {
                    diff=abs(other-j);
                }

               }
           }
           
          
                return diff;
	    
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