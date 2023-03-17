//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

long long int no_of_subarrays(int n, vector<int> &arr) {
   
   
   unordered_map<long long ,long long> mp;
   mp[0]=1;
   
   long long sm=0;
   long long ans=0;
   
   for(int i=0;i<arr.size();i++)
   {
       sm+=arr[i];
       
       if(mp.find(sm)!=mp.end())
        ans+=mp[sm];
        
        mp[sm]++;
   }
   return ans;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << no_of_subarrays(n, arr) << endl;
    }
}

// } Driver Code Ends