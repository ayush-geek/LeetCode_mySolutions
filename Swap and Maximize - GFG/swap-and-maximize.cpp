//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends


long long int maxSum(int arr[], int n)
{
    long long sm=0;
    vector<int> res;
    sort(arr,arr+n);
    int i=0;
    int j=n-1;
    int fg=0;
    while(i<=j)
        {
            if(!fg)
                res.push_back(arr[i++]);
            else
                res.push_back(arr[j--]);
            fg=1-fg;
        }
    
    for(int i=1;i<n;i++)
    {
        sm+=abs(res[i]-res[i-1]);
    }
    
    sm+=abs(res[n-1]-res[0]);
    
    return sm;
    
}