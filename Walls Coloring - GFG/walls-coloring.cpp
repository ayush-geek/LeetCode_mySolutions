//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    
    int solve(int i ,int lst,vector<vector<int>>& colors,vector<vector<int>>& dp,int N)
    {
        if(i<0)
            return 0;
            
        if(dp[i][lst]!=-1)
            return dp[i][lst];
        
        int a=1e9,b=1e9,c=1e9;
        
        if(lst!=0)
        {
            a=colors[i][0]+solve(i-1,0,colors,dp,N);
        }
        if(lst!=1)
        {
            b=colors[i][1]+solve(i-1,1,colors,dp,N);
        }
        if(lst!=2)
        {
            c=colors[i][2]+solve(i-1,2,colors,dp,N);
        }
            
           // cout<<min(a,min(b,c))<<endl;
            
        return dp[i][lst]=min(a,min(b,c));
    }


    int minCost(vector<vector<int>> &colors, int N) {
        // Write your code here.
        
        //solve(i,lst,colors,n,dp);
        
        vector<vector<int>> dp(N,vector<int> (4,-1));
        
        return solve(N-1,3,colors,dp,N);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends