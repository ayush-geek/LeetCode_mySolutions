//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        long long ans=0;
        long long l=1;
        long long h=x;
        
        while(l<=h)
        {
            long long mid=(l+h)/2;
            
            
            if(mid*mid<=x)
            {
                ans=mid;
                
                if(mid*mid==x)
                    return ans;
            }
                
            if(mid*mid>x)
                h=mid-1;
            else
                l=mid+1;
        }
        
      
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends