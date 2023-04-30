//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
        
        sort(intervals.begin(),intervals.end());
        
        map<int,int> mp;
        
        for(auto& ele: intervals)
        {
            mp[ele[0]]++;
            mp[ele[1]+1]--;
            
            
        }
        int ans=0;
        int pos=-1;
        int fg=0;
        for(auto& ele: mp)
        {
                ans+=ele.second;
                if(ans>=k)
                {
                    pos=max(pos,ele.first);
                    fg=1;
                }
                if(ans<k && fg==1)
                {
                    pos=max(pos,ele.first-1);
                    fg=0;
                }
        }
        return pos;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends