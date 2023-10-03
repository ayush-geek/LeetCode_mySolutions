//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int ct=0;
        int mxj=0;
        int cur=0;
        
        for(int i=0;i<n-1;i++)
        {   
             cur=max(cur,i+arr[i]);
            
            if(i==mxj)
            {
                ct++;
                mxj=cur;
                
            }
            
            //cout<<cur<<" "<<i<<" "<<ct<<endl;
            
          
            
                
            
        }
        if(mxj<n-1)
            return -1;
        return ct;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends