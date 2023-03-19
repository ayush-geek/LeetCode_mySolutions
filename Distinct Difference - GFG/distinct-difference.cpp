//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    vector<int> getDistinctDifference(int N, vector<int> &A) {
        // code here
        
         vector<int> res;
         
         vector<int> suf;
        set<int> st;
        
        for(int i=N-1;i>=0;i--)
        {
            suf.push_back(st.size());
            st.insert(A[i]);
            
            //cout<<suf[i]<<" ";
        }
        // cout<<endl;
        reverse(suf.begin(),suf.end());
        
        set<int> st2;
        
        for(int i=0;i<N;i++)
        {
            res.push_back(st2.size()-suf[i]);
            
            st2.insert(A[i]);
            
        }
            
        return res;
         
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends