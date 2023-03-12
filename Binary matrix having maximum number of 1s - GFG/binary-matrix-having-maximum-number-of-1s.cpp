//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        //code here
        
        int sr=0;
        int sc=N-1;
        int ar=0;
        
        int ct=0;
        while(sr<N && sc>=0)
        {
            if(mat[sr][sc]!=1)
            {
                sr++;
              
            }
                
            else
            {
               
               
                if(N-sc>ct)
                    ar=sr;
                  ct=max(ct,N-sc);
                   sc--;
                 
            }
                
        }
        
        return {ar,ct};
        
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends