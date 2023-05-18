//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
        // Code Here
        
        map<char,char> mp;
        
        for(auto& ele: a)
        {
            // st.insert(ele);
            mp[ele]=ele;
        }
        
        int k=0;
        int fg=0;
       for(int i=0;i<a.size();i++)
        {
           char z=a[i];
           
           for(auto& ele: mp)
           {
               if(ele.first<z)
               {
                   mp[z]=ele.first;
                   mp[ele.first]=z;
                   fg=1;
                   break;
               }
               else if(ele.first==z)
                mp.erase(z);
                else
                    break;
           }
           
           if(fg)
            break;
        }
        
        for(int i=0;i<a.size();i++)
        {   
            if(mp.find(a[i])!=mp.end())
                a[i]=mp[a[i]];
        }
        return a;
    }
    
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}

// } Driver Code Ends