//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        
     
            // return new 
        vector<int> d(D,0);
        d[0]=1;
        int lft=S-1;
        for(int i=D-1;i>0;i--)
        {
            if(lft>=9){
                d[i]=9;
                lft-=9;
            }
            else
            {
                d[i]+=lft;
                lft-=lft;
                break;
            }
        }
        
        if(lft+d[0]>9)
            return "-1";
        d[0]+=lft;
        
      
        string ss;
        
        for(int i=0;i<D;i++)
            {
                ss.push_back(d[i]+'0');
            }
            
           
            return ss;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends