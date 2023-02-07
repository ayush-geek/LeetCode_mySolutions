//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        
        int z=accumulate(arr,arr+N,0);
        
        if(z%2!=0)
            return false;
            
        int tgt=z/2;
        
        vector<vector<int>> dp(N+1,vector<int> (tgt+1,0));
        
        for(int i=0;i<=N;i++)
            dp[i][0]=1;
        
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=tgt;j++)
            {
                if(arr[i-1]<=j)
                    dp[i][j]=dp[i-1][j-arr[i-1]];
                dp[i][j]=dp[i][j] || dp[i-1][j];
            }
        }
        if(dp[N][tgt])
            return 1;
        return 0;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends