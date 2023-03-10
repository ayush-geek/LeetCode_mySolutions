//{ Driver Code Starts
// Initial Template for C++

// {Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isBSTTraversal(vector<int>& nums) {
        // your code here
        
        //chk if array is sorted
        
        int n=nums.size();
        if(n==1)
            return true;
    
        int fg=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1]>0)
                continue;
            else
            return false;
            
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            nums[i] = k;
        }

        Solution ob;
        bool res = ob.isBSTTraversal(nums);
        if (res)
            cout << "True";
        else
            cout << "False";

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends