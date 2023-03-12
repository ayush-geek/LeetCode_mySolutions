//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
   public:
    int findSum(int A[], int n)
    {
    	    
    	    //2*n Compaprsrion
    	    
    	   int mn=A[0];
    	   int mx=A[0];
    	   
    	   for(int i=1;i<n;i++)
    	   {
    	       mn=min(mn,A[i]);
    	       mx=max(mx,A[i]);
    	   }
    	   
    	   return mn+mx;
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
	    int arr[n];
	    for(int i=0;i<n;i++)
	      cin>>arr[i];
	    Solution ob;  
	    int ans=ob.findSum(arr, n);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}

// } Driver Code Ends