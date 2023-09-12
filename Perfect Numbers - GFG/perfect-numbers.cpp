//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        // code here
        // vector<long long> factors;
        long long sm=0;
        for(long long i=1;i<=sqrt(N);i++)
        {   
            if(N%i==0)
            {
            if(N/i==i)
            {
                // factors.push_back(i);
                sm+=i;
            }
            else{
                // factors.push_back(i);
                // factors.push_back(N/i);
                sm+=i;
               
                sm+=N/i;
            }
            }
            // cout<<sm<<endl;
        }
        // cout<<sm<<endl;
        return sm-N==N;
        
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
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends