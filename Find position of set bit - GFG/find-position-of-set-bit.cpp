//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        // code here
        
        int st=__builtin_popcount(N);
        
        if(st==0 || st>1)
            return -1;
        
        int ans=N;
        
        int ct=0;
        while(ans>0)
        {
            ct++;
            if(ans&1)
                return ct;
            ans>>=1;
        }
            
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends