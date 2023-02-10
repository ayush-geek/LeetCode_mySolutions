//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        
        
        map<char,int> mp;
        
        // (s.begin(),s.end());
        for(auto &ele:s)
            mp[ele]++;
        string t="balloon";
        
        int ans=INT_MAX;
        for(int i=0;i<t.size();i++)
        {   
            int z=mp[t[i]];
            
            if(t[i]=='l' || t[i]=='o')
                z=z/2;
                // cout<<
            ans=min(ans,z);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends