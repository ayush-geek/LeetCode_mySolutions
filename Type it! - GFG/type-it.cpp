//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        // code here
        
        //FIND lONGGWST SUBSTR
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                string t1=s.substr(i,j-i);
                string t2=s.substr(j,j-i);
                
                if(t1==t2){
                    //cout<<t1<<endl;
                    ans=max(ans,j-i);
                    
                }
            }
        }
      //  cout<<ans<<endl;
        if(ans>0)
            ans--;
        return n-ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends