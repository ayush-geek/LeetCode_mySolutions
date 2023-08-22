//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    
    void solve(int i,vector<int>& arr,int n,int sm,vector<int>& res)
    {
        if(i==arr.size())
        {
            res.push_back(sm);
            return ;
        }
        
        //take
        solve(i+1,arr,n,sm+arr[i],res);
        
        //nt
        solve(i+1,arr,n,sm,res);
    }

    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
    
        vector<int> res;
        int sm=0;
        solve(0,arr,n,sm,res);
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