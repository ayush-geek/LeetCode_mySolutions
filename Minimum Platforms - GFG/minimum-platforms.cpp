//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	map<int,int> mp;
    	
    	for(int i=0;i<n;i++)
    	{
    	    int a=arr[i];
    	    int b=dep[i];
    	    
    	    mp[a]++;
    	    mp[b+1]--;
    	}
    	
    	int sm=0;
    	int mx=0;
    	for(auto& ele: mp)
    	{
    	    sm+=mp[ele.first];
    	    mx=max(mx,sm);
    	    
    	}
    	return mx;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends