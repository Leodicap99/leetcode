/*
The way to appproach this problem is to an auxiliary pointer that will be merging the two sorted list.
The pointer will keep greedily selecting the minimum valued header pointer and connect them.
Once we have finished traversing evn one list we  break out of the loop and the pointer will point to the ListNode which is not NULL.


l1 = 1->3->5
l2 = 2->4->6

Lets use a dummy pointer that will pointing to the next smallest value and another pointer holding the first value of the list
that will be used to return pur final answer.

Let the ListNode poiter that we will be using to return be s.

First we try to fix s.

check the smaller value of the first value of each of the header pointers.
Since 1 is saller we make s to point to the first list and we move the header pointer of that list forward.

    1 -> 3 -> 5
    ^    ^
    |    |
    s,q  l1     
    
    2 -> 4 -> 6
    ^
    |
    l2
We use the dummy pointer lets say q that greedily selects the pointer with the least value be equal to s initially.

We check l1-> val > l2->val so we male q->next ppoint to l2 and we move l2 forward.

 1 -> 3 -> 5
 ^    l1
 |\
 s \
    v
   2 -> 4 -> 6
   q    l2

   	we e continue this linkage thruout and return s at the end.


*/
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)return l2;
        if(!l2)return l1;
        ListNode* s;
        if(l1->val<=l2->val)
        {
            s=l1;
            l1=l1->next;
        }
        else 
        {
            s=l2;
            l2=l2->next;
        }
        ListNode* q=s;
        while(l1&&l2)
        {
            if(l1->val<=l2->val)
            {
                q->next=l1;
                l1=l1->next;
            }
            else
            {
                q->next=l2;
                l2=l2->next;
            }
            q=q->next;
        }
        q->next=(l1)?l1:l2;
        return s;
    }
