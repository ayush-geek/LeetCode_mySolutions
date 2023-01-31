//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string A, string B) {
        // code here
        
        int sz=B.size();
        string tmp=A;
        int k=0;
        while(tmp.size()<2*sz)
        {     k++;
          // cout<<tmp.size()<<endl;
            
            if(tmp.find(B)!=-1)
                return k;
       
          tmp.append(A);
         
        }
            
        string tt=A+A;
        if(tt.find(B)!=-1)
            return 2;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends