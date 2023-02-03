//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C){
        //code here
        
        //0 up
        //1 right
        //2 down
        //3 left
        
       int i=0;
       int j=0;
       int pr=0;
       int pc=j;
       int d=1;
       while(i>=0 && i<R && j>=0 && j<C)
       {    
           pr=i;
           pc=j;
           
           if(matrix[i][j]==1)
           {
               d=(d+1)%4;
               matrix[i][j]=0;
           }
           
           if(d==0)
            i=i-1;
        else if(d==1)
            j=j+1;
        else if(d==2)
            i=i+1;
        else
            j=j-1;
           
       }
       
       return {pr,pc};
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends