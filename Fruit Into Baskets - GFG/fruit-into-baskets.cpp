//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {
        
        int j=0;
        int n=N;
        int ans=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[fruits[i]]++;
            
            if(mp.size()>2)
                {
                    while(mp.size()>2)
                    {
                        mp[fruits[j]]--;
                        if(mp[fruits[j]]==0)
                            mp.erase(fruits[j]);
                        
                        j++;
                    }
                }
            ans=max(ans,i-j+1);
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
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends