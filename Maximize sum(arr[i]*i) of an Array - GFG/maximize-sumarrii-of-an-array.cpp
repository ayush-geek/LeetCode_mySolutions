//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int mod=1e9+7;
    int Maximize(int arr[],int n)
    {
        // Complete the function
        
        long long sm=0;
        
        sort(arr,arr+n);
        
        
        for(int i=0;i<n;i++)
        {
            sm=(sm+(long long)i*arr[i])%mod;
        }
        return sm%mod;
        
    }
};

//{ Driver Code Starts.
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.Maximize(a,n)<<endl;
    }
}
// } Driver Code Ends