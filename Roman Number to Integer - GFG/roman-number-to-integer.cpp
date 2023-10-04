//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        
        unordered_map<string,int> mp{{"I",1},{"V",5},{"X",10},{"L",50},{"C",100}
        ,{"D",500},{"M",1000}};
        
    
        int n=str.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {   
            string t="";
            t+=str[i];
            if(i>=1)
            {
                string prev="";
                prev+=str[i-1];
                
                if(mp[prev]<mp[t])
                    ans+=mp[t]-2*mp[prev];
                else
                    ans+=mp[t];
            }
            
            else
            ans+=mp[t];
        }
        
        return ans;
        
        
        
        
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
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends