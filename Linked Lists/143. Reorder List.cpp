/*
There are just 3 basic steps to follow to solve this question:-
1. Find the middle of the list.
2.Reverse the list from middle to end.
3. merge the 1st half and 2nd half of the list.

Lets try this on some of the examples:-
1->2->3->4

Middle is 2 so we try to reverse 3 and 4
1->2->4->3
Note that for merging purposes we will be making slow->next=NULL  so we can treat this as 2 different lists.

1->2
4->3

merging
1->4->2->3
*/

    void mergelist(ListNode*p,ListNode* q)         //For merging
    {
        ListNode* t;
        while(q)
        {
            t=p->next;
            p->next=q;
            q=q->next;
            p=p->next;
            p->next=t;
            p=p->next;
        }
    }
    ListNode* reverse(ListNode* head)                //reversing the second half of the ll
    {
        ListNode* prev=NULL,*curr=head,*next;
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* findmid(ListNode* head)                //Finding the middle
    {
        ListNode* slow=head,*fast=head;
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid=slow->next;
        slow->next=NULL;
        return mid;
    }
    void reorderList(ListNode* head) {
        if(!head)return;
        ListNode* p=head;
        ListNode* q=findmid(head);
        q=reverse(q);
        mergelist(p,q);
    }