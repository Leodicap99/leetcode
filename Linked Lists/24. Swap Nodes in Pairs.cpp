/*
This is a pointer intensive problem.
The way to crack this is to use a prev pointer and a next pointer.

Let head = 1->2->3->4
     1 -> 2 -> 3 -> 4 
 ^   ^
 |   |
 p   c

 now we want to swap 1 and 2.
 so we make p->next to point to 2(making 2 the first member)
 then we make c->next = c->next->next
 Now the only problem is 2 should connect to 1.
 p>next=2 so p->next->next=c and c=c->next

 thus we have swapped 2 and 1

    2 -> 1 -> 3 -> 4
         ^    ^
         |    |
         p    c 
  We perform the same procedure which swaps 3 and 4.

    2->1->4->3

   */
        ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* newhead=new ListNode(0);
        newhead->next=head;
        ListNode* prev=newhead,*curr=head;
        while(curr&&curr->next)  //<--------------- because if curr->next is NULL and curr->next=curr->next->next will throw an error.
        {
            prev->next=curr->next;
            curr->next=curr->next->next;
            prev->next->next=curr;
            prev=curr;
            curr=curr->next;
        }
        return newhead->next;
    }