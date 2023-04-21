//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<string> res;
    void solve(string& tmp,int n)
    {
        if(tmp.size()==n)
        {
            res.push_back(tmp);
            return ;
        }
        
        if(tmp.size()==0 || tmp.back()=='0')
        {
            tmp.push_back('1');
            solve(tmp,n);
            tmp.pop_back();
            tmp.push_back('0');
            solve(tmp,n);
            tmp.pop_back();
        }
        
        else  
        {
            tmp.push_back('0');
            solve(tmp,n);
             tmp.pop_back();
        }
    
        
    }
    void generateBinaryStrings(int num){
       
       string tmp="";
       
        solve(tmp,num);
       sort(res.begin(),res.end());
       for(auto& ele: res)
        cout<<ele<<" ";
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends