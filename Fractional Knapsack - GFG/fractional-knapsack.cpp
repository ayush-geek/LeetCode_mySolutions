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
            double ans=(double)arr[i].value/(arr[i].weight);
            vp.push_back({ans,arr[i].weight});
        }
        
        sort(vp.rbegin(),vp.rend());
        double ans=0;
        for(int i=0;i<vp.size();i++)
        {
            double tmp=vp[i].first;
            int w=vp[i].second;
            //cout<<tmp<<endl;   
            if(w<=W)
            {
                ans+=(tmp)*w;
                W-=w;
            }
            else
            {
                ans+=(W)*tmp;
                break;
            }
        }
        return ans;
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