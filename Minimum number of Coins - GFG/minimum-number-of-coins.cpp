//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        //Greedy Approach 
        //Try to take Max Cur Note
        
        vector<int> v={ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        vector<int> res;
        
        reverse(v.begin(),v.end());
       
       for(int i=0;i<v.size();i++)
       {    
           int z1=N/v[i];
            N=N-v[i]*z1;
           while(z1>0)
           {
               res.push_back(v[i]);
               z1--;
           }
           
          
       }
       
       return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends