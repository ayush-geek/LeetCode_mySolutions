//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        vector<pair<int ,int>> vp;
        
        for(int i=0;i<n;i++)
        {
            int z=__builtin_popcount(arr[i]);
            vp.push_back({z,i});
        }
        
        sort(vp.begin(),vp.end(),[](pair<int,int>& a,pair<int,int>& b){
            if(a.first==b.first)
                return a.second<b.second;
            return a.first>b.first;
        });
        vector<int> tmp;
        for(int i=0;i<n;i++)
        {
            tmp.push_back(arr[i]);
        }
        for(int i=0;i<n;i++)
        {
            arr[i]=tmp[vp[i].second];
        }
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends