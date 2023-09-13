//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
        
        int sm=N*9;
        
        if(sm<S )
            return "-1";
        if(S==0)
        {
            if(N==1)
                return "0";
            return "-1";
        }
        string s;
        
        for(int i=0;i<N;i++)
        {
            int cur=min(9,S);
            S-=cur;
            s+=to_string(cur);
        }
        //reverse(s.begin(),s.end());
        return s;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends