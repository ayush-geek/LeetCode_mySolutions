//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	int m=1e9+7;
	
	   int solve(int i,string& s,vector<int>& dp)
	   {
	       if(i==s.size())
	        return 1;
	        if(dp[i]!=-1)
	            return dp[i];
	       
	       int ans=0;
	       
	       if(s[i]=='0')
	        return 0;
	        if( i+1<s.size() && ((s[i]=='2' && (s[i+1]<='6')  )|| s[i]=='1'))
            ans+=solve(i+2,s,dp);
	       
	        ans+=(solve(i+1,s,dp)) %m;
	       
	       return dp[i]=ans%m;
	   }
	
		int CountWays(string str){
		    // Code here
		
		    
		    int n=str.size();
		    vector<int> dp(n,-1);
		    
		    return solve(0,str,dp);
		    
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends