//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        
        vector<pair<double,int>> vp;
        
        for(int i=0;i<n;i++)
        {
            double ans= (arr[i].value*1.0) /(arr[i].weight);
            vp.push_back({ans,i});
        }
        
        sort(vp.begin(),vp.end(),[](pair<double,int>& a,pair<double,int>& b){
            return a.first>=b.first;
        });
        
        double pft=0;
        for(int i=0;i<n;i++)
        {   
            int z=vp[i].second;
            if(arr[z].weight<=W){
                pft+=arr[z].value;
                W-=arr[z].weight;
            }
            else
            {
                pft+=vp[i].first *W;
                break;
            }
                
        }
        return pft;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends