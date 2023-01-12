//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
       
       vector<pair<int,int>> vp;
       
       for(int i=0;i<n;i++)
       {
           vp.push_back({end[i],start[i]});
       }
       
       sort(vp.begin(),vp.end());
        int ans=0;
        int pre=-1;
       for(int i=0;i<n;i++)
        {
            if(i==0)
                pre=vp[i].first;
            else if(vp[i].second<=pre)
            {
                ans++;
            }
            else
                pre=vp[i].first;
        }
        
        return n-ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends