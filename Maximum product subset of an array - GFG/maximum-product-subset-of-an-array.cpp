//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int mod=1e9+7;
    long long int findMaxProduct(vector<int>&a, int n){
        //Write your code here  
        
      int cz=0;
      int cp=0;
      int cn=0;
      long long p=1ll;
      long long ne=1ll;
      int mn=INT_MIN;
    
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
            cz++;
        else if(a[i]>0)
        {
            p=(p*(long long)a[i] )%mod;
            cp++;
            
        }
        else
        {
            ne=(ne*(long long)a[i] )%mod;
            mn=max(mn,a[i]);
            cn++;
        }
        
    }
    //cout<<p<<" "<<ne<<endl;
    if(cz==n)   
        return 0;
    else if(cp==0 )
    {
        if(cn==1 && cz>0)
            return 0;
        else if(cn==1 )
            return mn;
        else if(cn%2==0)
            return ne;
        else
            return ne/mn;
    }
  
    else if(cn==0 )
        return p;
    else
    {
        if(cn%2==0) 
            return (p*ne)%mod;
        ne=ne/mn;
          return (p*ne)%mod;
    }
    return -1;
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
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    long long int ans = ob.findMaxProduct(arr, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends