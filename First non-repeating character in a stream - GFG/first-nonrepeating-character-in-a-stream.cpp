//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	      
		string FirstNonRepeating(string A){
		   vector<int> v(26,0);
		   unordered_map<char,int> mp;
		   string res;
		   
		   for(int i=0;i<A.size();i++)
		   {
		       v[A[i]-'a']++;
		       if(v[A[i]-'a']>1)
		        mp[A[i]]=-1;
		       else
		        mp[A[i]]=i;
		        
		    
		          char tmp='#';
		          int mn=i;
		          for(auto& ele: mp)
		          {
		              if(ele.second!=-1)
		              {
		                  if(ele.second<=mn)
		                  {
		                      mn=min(mn,ele.second);
		                      tmp=ele.first;
		                  }
		              }
		          }
		        res.push_back(tmp);
		           
		       
		   }
		   return res;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends