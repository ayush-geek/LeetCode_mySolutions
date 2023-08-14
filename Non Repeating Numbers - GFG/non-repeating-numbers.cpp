//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            res=res^nums[i];
        }
        
        // res=a^b
        //cout<<res<<endl;
        int a=0;
        int b=0;
        
        int bit =res & ~(res - 1);;
      //  cout<<bit<<endl;
        
        for(int i=0;i<nums.size();i++)
        {
            
            if(bit & (nums[i])){
             
                a=a^nums[i];
                
                
            }
            else
                 b=b^nums[i];
        }
        return {min(a,b),max(a,b)};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends