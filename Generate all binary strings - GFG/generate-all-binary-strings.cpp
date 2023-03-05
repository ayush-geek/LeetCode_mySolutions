//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

vector<string> res;

    void solve(int i,int& num,string tmp)
    {
        if(i==num)
        {
            // cout<<tmp<<" ";
            res.push_back(tmp);
            return ;
        }
        
        if(tmp.empty())
        {
            tmp.push_back('0');
            solve(i+1,num,tmp);
            tmp.pop_back();
            tmp.push_back('1');
            solve(i+1,num,tmp);
            tmp.pop_back();
        }
        else
        {
            if(tmp.back()=='1')
                {
                    tmp.push_back('0');
                    solve(i+1,num,tmp);
                }
            else
            {
                tmp.push_back('1');
                solve(i+1,num,tmp);
                tmp.pop_back();
                
                
                tmp.push_back('0');
                solve(i+1,num,tmp);
                tmp.pop_back();
            }
        }
        
    }

    void generateBinaryStrings(int& num){
        
        string tmp="";
        solve(0,num,tmp);
        
        sort(res.begin(),res.end());
        
        for(auto&ele: res)
            cout<<ele<<" ";
        
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        // cout << setprecision(9) << obj.switchCase(choice,vec) << endl;
        obj.generateBinaryStrings(n);
        cout << endl;
        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends