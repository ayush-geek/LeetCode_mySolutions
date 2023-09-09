//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	int mod=1e9+7;
	unordered_map<int,long long> dp;
		int countWays(int n, int m)
	{
	    // Code here.
	    
	    
	    if(n<m)
	       return 1;
	       
	   if(n==m)
	    return 2;
	    
	    if(dp.find(n)!=dp.end())
	        return dp[n];
	    
	    
	    return dp[n]=((long long)countWays(n-1,m) + (long long)countWays(n-m,m))%mod;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.countWays(n, m);
		cout << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends