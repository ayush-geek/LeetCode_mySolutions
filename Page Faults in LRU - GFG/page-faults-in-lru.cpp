//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
      
     // queue<int> q;
      unordered_map<int,int> mp;
    // unordered_set<int> st;
      int ct=0;
      for(int i=0;i<N;i++)
      {
         
          if(mp.size()<C )
          { 
              if(mp.find(pages[i])!=mp.end())
                  mp[pages[i]]=i;
            
            else
            {
              ct++;
              mp[pages[i]]=i;
           
                
            }
              
          }
          else
          { 
               if(mp.find(pages[i])!=mp.end()){
                  mp[pages[i]]=i;
                   continue;
               }
                  
              int olde=pages[i-1];
              int pos=i-1;
             for(auto& ele: mp)
             {
                 if(ele.second<pos)
                 {
                     pos=ele.second;
                     olde=ele.first;
                 }
                 
             }
             mp.erase(olde);
             
             ct++;
             mp[pages[i]]=i;
          }
            
      }
      return ct;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}
// } Driver Code Ends