//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    int solve(double mid,vector<int> &stations)
    {   
         int n=stations.size();
        int ct=0;
         for(int i=0;i<n-1;i++)
      { 
          int num=(int)(stations[i+1]-stations[i])/mid;
          
        //   if(num*mid==(stations[i+1]-stations[i]))
        //     num--;
        
        ct+=num;
      }
      
      return ct;
    }
  
    double findSmallestMaxDist(vector<int> &stations, int k){
      // Code here
      int n=stations.size();
      double low=0;
      double high=stations[n-1]-stations[0];
    //   for(int i=0;i<n-1;i++)
    //   {
    //       high=max(high,(double)stations[i+1]-stations[i]);
    //   }
      double dif=1e-6;
      while(high-low>dif)
      {
          double mid=(low+high)/2.0;
          
          int cnt=solve(mid,stations);
          
         if(cnt>k)
            low=mid;
        else
            high=mid;
      }
      return high;
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
    vector<int> stations(n);
    for (int i = 0; i < n; i++)
    {
      cin >> stations[i];
    }
    int k;
    cin >> k;
    Solution obj;
    cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k) << endl;
  }
  return 0;
}
// } Driver Code Ends