//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        // Code here
        
        sort(arr.begin(),arr.end());
        unordered_set<int> s;
        long long ans=0;
        
        for(int i=0;i<N;i++)
        {
            if(s.find(arr[i])==s.end())
            {
                //Not pst
                s.insert(arr[i]);
            }
            
            else
            {
                int z=arr[i];
                
                while(s.count(z)==1)
                {
                    z++;
                    ans++;
                }
                 s.insert(z);
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends