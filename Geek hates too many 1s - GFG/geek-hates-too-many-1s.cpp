//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    
    string to_bin(int n)
    {
        string res="";
        // int ct=0
        
        while(n>0)
        {
            if(n%2 ==0)
             {
                 res.push_back('0');
                // ct=0;
                 
             }
             else
             {  
                 
                 
                 res.push_back('1');
             }
             n=n/2;
        }
        
        return res;
    }
    
    int noConseBits(int n) {
        // code here
        
        //find Binary
        
        string tmp=to_bin(n);

                reverse(tmp.begin(),tmp.end());
                        //   cout<<tmp<<endl;
        int ct=0;
        for(int i=0;i<tmp.size();i++)
        {
            if(tmp[i]=='1')
                ct++;
            else
                ct=0;
            if(ct==3)
            {
                tmp[i]='0';
                ct=0;
            }
            
        }
        
    //   cout<<tmp<<endl;
        int res=0;
        // int pw=0;
        reverse(tmp.begin(),tmp.end());
        for(int i=0;i<tmp.size();i++ )
        {
            if(tmp[i]=='1')
                res=pow(2,i)+res;
        }
        
        return res;
    }
};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends