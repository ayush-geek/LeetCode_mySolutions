//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        vector<long long> res;
        vector<int> tmp=arr;
        sort(tmp.begin(),tmp.end());
        
        vector<long long> pref(n,0ll);
         for(int i=1;i<tmp.size();i++)
        {   
            
              
                    pref[i]=(long long)pref[i-1] +(long long) tmp[i-1];
        }
        
        for(int i=0;i<arr.size();i++)
        {
            int ub=upper_bound(tmp.begin(),tmp.end(),arr[i]-1)-tmp.begin();
            
            long long sm=pref[ub];
            res.push_back(sm);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends