//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string s, int x){
     
        
       
        int mx=-1;

        
        for(int i=0;i<N;i++)
        {
            if(s[i]=='1' )
                {
                    if(i-x<=mx+1)
                        {
                            mx=max(mx,i+x);
                        }
                    else
                        return false;
                }
           
        }
        
       
      
        
        if(mx>=N-1)
            return true;
        return false;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends