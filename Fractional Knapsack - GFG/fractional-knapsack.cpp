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
        
        sort(arr,arr+n,[](Item& a,Item& b)
        {
           double a1=(double)a.value/a.weight;
           double a2=(double)b.value/b.weight;
         
            return a1>=a2;
          
        });
        
        double ans=0;
        
        for(int i=0;i<n;i++)
        {   
            double a1=(double)arr[i].value/arr[i].weight;
            // double to_take=min(W,arr[i].weight)*a1;
            if(W>=arr[i].weight)
                ans+=arr[i].value;
            else
            {
                ans+=W*a1;
                break;
            }
          
            W-=arr[i].weight;
            
            
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