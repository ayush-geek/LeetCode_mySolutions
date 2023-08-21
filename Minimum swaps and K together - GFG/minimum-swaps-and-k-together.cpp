//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int nums[], int n, int k) {
        // Complet the function
        
        int ct=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=k)
                ct++;
        }
        
        
        int i=0;
        int j=0;
        int ans=n;
        int ct2=0;
        
        while(i<ct)
        {
            if(nums[i]<=k)
                ct2++;
            i++;    
          
        }
          ans=min(ans,ct-ct2);
        while(i<n)
        {
            if(nums[j]<=k)
                ct2--;
            j++;
            
            if(nums[i]<=k)
                ct2++;
                
            ans=min(ans,ct-ct2);  
            i++;
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends