//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends


 int solve(string str1, string str2) 
	{ 
	    // Your code goes here
	    
	    int n1=str1.size();
	    int n2=str2.size();
	    
	    
	    vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));
	    
	    int ans=0;
	    for(int i=1;i<=n1;i++)
	    {
	        for(int j=1;j<=n2;j++)
	        {
	            if(str1[i-1]==str2[j-1])
	                dp[i][j]=1+dp[i-1][j-1];
	           else
	           dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	           
	           ans=max(ans,dp[i][j]);
	        }
	    }
	    
	    return n1-ans;
	    
	    
	} 

int minDeletions(string A, int n) { 
    //complete the function here 
      string B=A;
        reverse(B.begin(),B.end());
        
        return  solve(A,B);
} 