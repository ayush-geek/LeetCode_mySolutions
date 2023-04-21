//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod=1e9+7;
	  int solve(int i,int arr[],int& ct,int& sum,int& cs,int& n, vector<vector<int>>& dp)
    {   
        
        if(i==n)
        {
                
             return cs==sum;
        }
        
        if(dp[i][cs]!=-1)
            return dp[i][cs];
        
        //take
        int l=0;
        if(cs+arr[i]<=sum)
        {
        cs+=arr[i];
        l=solve(i+1,arr,ct,sum,cs,n,dp)%mod;
        cs-=arr[i];
        }
        
        //Not_take
          int r=solve(i+1,arr,ct,sum,cs,n,dp)%mod;
    
        
        return dp[i][cs]=(l+r)%mod;
    }
  
	
	int perfectSum(int arr[], int n, int sum)
	{
        int ct=0;
        int cs=0;
         vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        return solve(0,arr,ct,sum,cs,n,dp);
       
        
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