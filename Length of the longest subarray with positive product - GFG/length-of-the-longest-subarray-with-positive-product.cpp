//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
           
           long long prod=1;
           int pz=-1;
           int len=0;
           int fn=-1;
           int cn=0;
           
           
           for(int i=0;i<n;i++)
           {
               
               if(arr[i]<0)
               {
                   cn++;
                   if(fn==-1)
                    fn=i;
               }
               if(arr[i]==0)
               {
                   fn=-1;
                   cn=0;
                   pz=i;
               }
               else
               {
                   if(cn%2==0)
                   {
                       len=max(len,i-pz);
                       
                   }
                   else
                   {
                       len=max(len,i-fn);
                   }
                    
               }
               
               

                
           }
           return len;
           
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends