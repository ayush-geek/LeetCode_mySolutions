//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // code here
        
        stack<char> st;
        
        for(int i=0;i<s.size();i++)
        {
            if(st.empty() || st.top()!=s[i])
                st.push(s[i]);
            else 
            {
                while(!st.empty() && st.top()==s[i])
                {
                    st.pop();
                }
               
            }
        }
        
        
        string tmp;
        
        while(!st.empty())
        {
            tmp.push_back(st.top());
            st.pop();
        }
        
        reverse(tmp.begin(),tmp.end());
        if(tmp.empty())
            return "-1";
        return tmp;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends