//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	   int mod=1e9+7;
	   vector<vector<int>> dp;
	   
	int solve(int i,int arr[],int n,int sum)
	{
	    if(i<0)
	        return sum==0;
	   if(dp[i][sum]!=-1)
	    return dp[i][sum];
	    
	   int take=0,not_take=0;
	   
	   if(arr[i]<=sum)
	   {
	       take=(take+solve(i-1,arr,n,sum-arr[i]))%mod;	   
	       
	   }
	    
	    not_take=(not_take+solve(i-1,arr,n,sum))%mod;
	    
	    return dp[i][sum]=(take+not_take)%mod;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        dp.resize(n+1,vector<int> (sum+1,-1));
        sort(arr,arr+n);
        return solve(n-1,arr,n,sum);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends