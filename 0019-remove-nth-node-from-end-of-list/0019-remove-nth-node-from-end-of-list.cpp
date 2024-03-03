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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       //2 n
       //5 len
       //5-2+1 th
       //l-n+1en
        ListNode* tmp=head;
       ListNode* prev=NULL;
       ListNode* start=tmp;
       ListNode* tail=tmp;

       while(n>1)
       {
           tmp=tmp->next;
            n--;
       }
        tail=tmp;

       while(tail->next!=NULL)
       {    
           prev=start;
           start=start->next;
           tail=tail->next;
       }
        if(prev==NULL)
            return head->next;
        else
             prev->next=start->next;


        return head;

    }
};