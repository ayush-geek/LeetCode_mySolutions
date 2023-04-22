//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

    void solve(int i,vector<int>& arr,int& cs,vector<int>& res)
    {
        if(i==arr.size())
        {
            res.push_back(cs);
            return ;
        }
        
        //take
        cs+=arr[i];
        solve(i+1,arr,cs,res);
        cs-=arr[i];
        
        
        //not take
        solve(i+1,arr,cs,res);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> res;
        int cs=0;
        solve(0,arr,cs,res);
        
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends