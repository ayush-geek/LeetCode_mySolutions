//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    unordered_map<int,long long> mp;
    int mod=1e9+7;
    long long numberOfWays(long long N) {
        //code here
        if(N<=2)
            return N;
      
      
        long long prev=1;
        long long prev2=2;
        
        for(int i=3;i<=N;i++)
        {
            long long ans=((long long)prev+ (long long)prev2)%mod;
            prev=prev2;
            prev2=ans;
        }
        return prev2;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.numberOfWays(N) << endl;
    }
    return 0;
}
// } Driver Code Ends