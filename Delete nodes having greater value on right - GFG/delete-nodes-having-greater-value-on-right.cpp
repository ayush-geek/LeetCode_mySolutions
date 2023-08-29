//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{   
    private:
    Node* reverse(Node* lst)
    {
        if(lst==NULL)
            return NULL;
            
       
        Node* prev=NULL;
        
        
        while(lst!=NULL)
        {   
             Node* nxt=lst->next;
             lst->next=prev;
             prev=lst;
             lst=nxt;
            
        }
        
        return prev;
    }

    
    public:
    Node *compute(Node *head)
    {
       
        Node* tmp=head;
        Node* r=reverse(tmp);
        Node* t2=r;
        
        Node* prev=NULL;
        
        while(r!=NULL)
        {   
          
            if(prev==NULL || prev->data<=r->data)
            {
        
                    if(prev==NULL)
                        prev=r;
                    else{
                        
                        prev->next=r;
                        prev=prev->next;
                      
                        
                    }
                 
            }
            //cout<<"ss "<<prev->data<<endl;
                 
            r=r->next;
        }
        
        prev->next=NULL;
        
        return reverse(t2);
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends