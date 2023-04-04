//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    
    stack<char> st;
    int ct1=0,ct2=0;
   
   for(int i=0;i<str.size();i++)
   {
       if(str[i]=='a')
       {
           if(i>0 && str[i-1]!='a')
            ct1++;
            else if(i==0)
                ct1++;
       }
       else
       {
            if(i>0 && str[i-1]!='b')
            ct2++;
            else if(i==0)
                ct2++;
       }
   }
   
   return min(ct1,ct2)+1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends