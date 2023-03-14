//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

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
	            if(str1[i-1]==str2[j-1] )
	                dp[i][j]=1+dp[i-1][j-1];
	           else
	           dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	           
	           ans=max(ans,dp[i][j]);
	        }
	    }
	    
	    return n1-ans;
	    
	    
	} 
    int findMinInsertions(string S){
       
       
       string t=S;
       reverse(S.begin(),S.end());
       
       return solve(S,t);
       
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends