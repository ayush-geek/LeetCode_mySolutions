//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/


   int prime[100001];

void sieve(){

    memset(prime,1,sizeof(prime));

    prime[0]=prime[1]=0;

    for(int i=2;i*i<100001;i++){

        if(prime[i]){

        for(int j=i*i;j<100001;j+=i){

            prime[j]=0;

        }

       }

    }

    

}

int binary_searchleft(int start,int end,vector<int>arr,int target){

    int ans=-1;

    while(start<=end){

      int mid=start+(end-start)/2;

      if(arr[mid]>target){

          end=mid-1;

      }else if(arr[mid]<target){

          ans=arr[mid];

          start=mid+1;

          

          

      }else{

          return arr[mid];

      }

    }

    return ans;

    

    

}

int binary_searchright(int start,int end,vector<int>arr,int target){

    int ans=-1;

    while(start<=end){

        int mid=start+(end-start)/2;

        if(arr[mid]>target){

            ans=arr[mid];

            end=mid-1;

        }else if(arr[mid]<target){

            

            start=mid+1;

        }else{

            return arr[mid];

        }

    }

    return ans;

}

class Solution{

public:

    Node *primeList(Node *head){

        sieve();

        vector<int>arr;

        for(int i=0;i<100001;i++){

            if(prime[i])arr.push_back(i);

        }

        Node *temp=head;

        while(temp!=NULL){

            int data=temp->val;

            int l=binary_searchleft(0,arr.size()-1,arr,data);

            int r=binary_searchright(0,arr.size()-1,arr,data);

            if(l==data||r==data){

                temp=temp->next;

                continue;

            }

            else if((l==-1)||(abs(l-data)>abs(r-data)))temp->val=r;

            else if((r==-1)|| (abs(r-data)>=abs(l-data)))temp->val=l;

            temp=temp->next;

            

            

        }

        return head;

        

        

 

    }
 

    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends