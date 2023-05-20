//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int minSubset(vector<int> &arr,int n){
        
        sort(arr.begin(),arr.end(),greater<int>());
        long long z=accumulate(arr.begin(),arr.end(),0ll);
        
        long long sm=0;
        int ct=0;
        for(int i=0;i<n;i++)
        {
            sm+=(long long)arr[i];
            ct++;
            
            if(sm>z-sm)
                return ct;
        }
        return -1;
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        cout<<ob.minSubset(Arr,N)<<endl;
    }
    return 0;
}
// } Driver Code Ends