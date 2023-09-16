//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    int mod=1e9+7;
    long long countWays(int n)
    {
        
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        if(n==3)
            return 4;
            
        long long prev=1;
        long long prev2=2;
        long long prev3=4;
        
        for(int i=4;i<=n;i++)
        {
            long long cur=((prev+prev2)%mod+prev3)%mod;
            prev=prev2;
            prev2=prev3;
            prev3=cur;
        }
        return prev3;
    
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends