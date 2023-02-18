//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
      
    //   sliding window
    int j=0;
    int ans=0;
    int ct=m;
    for(int i=0;i<n;i++)
    {
        if(arr[i]=='O')
            ct--;
            
        // if(ct==0)
        //     ans=max(ans,i-j+1);
         if(ct<0)
            {
                while(ct<0)
                {
                    if(arr[j]=='O')
                        ct++;
                    j++;
                }
                   
                
            }
     
            ans=max(ans,i-j+1);
    }
    return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends