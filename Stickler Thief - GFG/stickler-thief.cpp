//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int prev=-1,prev2=-1;
        if(n==1)
            return arr[0];
        
        if(n==2)
            return max(arr[0],arr[1]);
            
        prev=arr[0];
        prev2=max(arr[0],arr[1]);
        
        for(int i=3;i<=n;i++)
        {
            int cur=max(prev2,prev+arr[i-1]);
            prev=prev2;
            prev2=cur;
        }
        return prev2;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends