//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete below method */
using namespace std;
class Solution{
    public:
    
    int solve(int i,int j,int arr[],int n,vector<vector<int>>& dp)
    {
        if(i>=n)
            return 0;
            
        if(dp[i][j+1]!=-1)
            return dp[i][j+1];
        
        vector<int> tmp;
        int t=INT_MAX;
        int nt=INT_MAX;
        int mn=arr[i];
        
        //012345
        //5-4
        
        
        // if(i-j<4) 
           t=arr[i]+solve(i+1,i,arr,n,dp);
        if(i-j<4)  
            nt=solve(i+1,j,arr,n,dp);
        
        // cout<<t<<" "<<nt<<
        return dp[i][j+1]=min({t,nt});
        
    }
    
    int minSum(int arr[], int n){
        //Write your code here
        
        
        vector<vector<int>> dp(n+2,vector<int> (n+2,-1));
        int mn=arr[0];
        for(int k=0;k<n;k++)
            mn=min(mn,arr[k]);
              if(n<4)
              return mn;
        return solve(0,-1,arr,n,dp);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.minSum(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends