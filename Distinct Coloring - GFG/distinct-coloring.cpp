//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

    long long solve(int i,int N,int r[],int g[],int b[],int lst, vector<vector<long long>>& dp)
    {
        if(i==N)
            return 0;
            
        //Try all Possible cases
        if(dp[i][lst]!=-1)
            return dp[i][lst];
        
        long long a1=LLONG_MAX;
        long long a2=LLONG_MAX;
        long long a3=LLONG_MAX;
        if(lst!=1)
            a1=r[i]+solve(i+1,N,r,g,b,1,dp);
        if(lst!=2)
            a2=g[i]+solve(i+1,N,r,g,b,2,dp);
        if(lst!=3)
             a3=b[i]+solve(i+1,N,r,g,b,3,dp);
            
        return dp[i][lst]=min(a1,min(a2,a3));
        
    }

    long long int distinctColoring(int N, int r[], int g[], int b[]){
        // 
        
        //Dynamic Programming
        vector<vector<long long>> dp(N,vector<long long> (4,-1));
      int lst=0;
        return solve(0,N,r,g,b,lst,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends