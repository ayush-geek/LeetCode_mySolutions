//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        // code here
        int need=S*M;
        
        //6 days can buy
        
        if(N<M)
            return -1;
            int ct=0;
        int cur=0;
        for(int i=1;i<=S;i++)
        {
            if(i%7==0)
            {
                if(cur<M*i)
                    return -1;
                ct++;
            }
            else
            {
                cur+=N;
            }
            
            if(cur>=need)
                return i-ct;
            
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends