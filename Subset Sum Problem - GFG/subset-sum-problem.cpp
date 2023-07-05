//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    
    int solve(int i,vector<int>& arr,int sum,vector<vector<int>>& dp)
    {   
        if(sum==0)
            return 1;
        if(i<0)
        {
           
                return 0;
        }
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        int p=0,np=0;
        if(arr[i]<=sum)
            p=solve(i-1,arr,sum-arr[i],dp);
        np=solve(i-1,arr,sum,dp);
        
        return dp[i][sum]=max(p,np);
            
    }

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int> (sum+1,0));
        
        for(int i=0;i<n;i++)
            dp[i][0]=1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {   int p=0,np=0;
                if(arr[i-1]<=j)
                    p=dp[i-1][j-arr[i-1]];
                np=dp[i-1][j];
                
                dp[i][j]=max(p,np);
            }
        }
            
        return dp[n][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends