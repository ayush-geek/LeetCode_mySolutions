//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    
    void delete_s(stack<int>& s,int ind)
    {
        if(s.size()==ind)
        {
            s.pop();
            return ;
        }
        
        int tmp=s.top();
        s.pop();
        delete_s(s,ind);
        s.push(tmp);
        
    }
    
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
       
        int el_ind=(sizeOfStack+1)/2;
        delete_s(s,el_ind);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends