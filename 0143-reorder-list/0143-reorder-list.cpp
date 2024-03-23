/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* middle(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head;
        

        while(fast!=NULL && fast->next!=NULL)
        {

            if(fast->next->next==NULL)
                {
                    break;
                }

            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }


    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;

        while(head!=NULL)
        {
            ListNode* tmp=head->next;
            head->next=prev;
            prev=head;
            head=tmp;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        //base case

        //Find Middle of LL
        ListNode* md=middle(head);
        ListNode* nh=md->next;
        md->next=NULL;
       // cout<<md->val;
        //reverse 2nd half

        ListNode* rv=reverse(nh);

        //traverse both simulateously
         //Update Link
    
    // cout<<head->val<<endl;
        ListNode* tmp=new ListNode(1);
        ListNode* d=tmp;


        while(head!=NULL)
        {   
            //cout<<head->val<<endl;
            d->next=head;
            d=d->next;
             head=head->next;
            if(rv!=NULL)
            {
               d->next=rv;
               d=d->next;
               
                rv=rv->next;
            }
            
        }

        // while(rv!=NULL)
        // {   
        //     cout<<rv->val<<endl;
        //     // d->next=head;
        //     // d=d->next;
        //     // if(rv!=NULL)
        //     // {
        //     //    d->next=rv;
        //     //    d=d->next;
               
        //         rv=rv->next;
        //     // }
        //      //head=head->next;
        // }
       head= tmp->next;

    }
};