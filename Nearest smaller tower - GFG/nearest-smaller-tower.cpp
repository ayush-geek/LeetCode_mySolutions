//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
    //2  stack 
    int n=arr.size();
    stack<int> st,st1;
    
    vector<int> res(n,0);
    
    for(int i=0;i<n;i++)
    {
        if(st.empty()){
            res[i]=-1;
            st.push(i);
        }
        else
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
            
            if(st.empty()) 
                    res[i]=-1;
            else
                res[i]=st.top();
            st.push(i);
        }
    }
    
    // for(int i=0;i<n;i++)
    //     cout<<res[i]<<" ";
    
    // cout<<endl;
    
    
    for(int i=n-1;i>=0;i--)
    {
        if(st1.empty()){
           // res[i]=-1;
            st1.push(i);
        }
        else
        {
            while(!st1.empty() && arr[st1.top()]>=arr[i])
                st1.pop();
            
            if(!st1.empty()) 
            {
                if(res[i]==-1 )
                    res[i]=st1.top();
                
                else if(abs(i-res[i]) ==abs(i-st1.top()) )
                {
                    if(arr[res[i]]>arr[st1.top()])
                        res[i]=st1.top();
                }
                
               else if(abs(i-res[i])>abs(i-st1.top()) )
                {
                 
                        res[i]=st1.top();
                }
                    
                    
            }
                
            st1.push(i);
            
           
        }
         //cout<<arr[st1.top()]<<" "<<res[i]<<endl;
    }
    
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
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends