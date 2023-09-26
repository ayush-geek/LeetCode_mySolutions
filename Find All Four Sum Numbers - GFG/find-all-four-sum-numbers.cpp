//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int target) {
        
        
        //4 sum
        
        //Sorted 4 
        
        //O(n2) space
        //O(n3) time complexity
        int n=arr.size();
        
        vector<vector<int>> res;
        
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<arr.size();i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                    //Now Using 2 Pointers 
                    //2 sum Problem
                    
                    int tgt =target-arr[i]-arr[j];
                   // cout<<tgt<<" ";
                    int l=arr.size()-1 ; // Last Element IN array
                  
                    for(int k=j+1;k<arr.size() && k<l && l>=0;)
                    {   //cout<<arr[k]<<" "<<arr[l]<<" "<<tgt<<endl;
                        
                        if(arr[k]+arr[l]==tgt)
                            {// cout<<"ys";
                                vector<int> quad = {arr[i],arr[j],arr[k],arr[l]};
                                 
                                
                            
                                res.push_back(quad);
                                  int le=arr[k];
                                    int ri=arr[l];
                            
                             while(k<l and arr[k]==le)
                                    k++;
                       
                       while(k<l and arr[l]==ri)
                           l--;
                                         
                                     
                                  
     
                              }
                        
                        else if(arr[k]+arr[l]>tgt)
                            l--;
                        
                        else
                            k++;
                            
                        
                    }
                     while(j+1<n and arr[j+1]==arr[j])
                   j++;
            }
            
            while (i + 1 < n && arr[i + 1] == arr[i]) 
             i++;   
        }
        
        
        return res;
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends