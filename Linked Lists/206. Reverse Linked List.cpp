/*
We will be using 3 pointers to tackle this job. Our main otive would e to just reverse the pointers.
Why 3 pointers?
Because to reverse a pointer u will be needing the current node previous node to which it points and the next node.
   1->2->3

   If example u want to reverse 1->2 to 2->1.Instead of swaping the nodes we use the above pointer based approach:

      1 -> 2
 ^    ^    ^
 |    |    |
prev curr  next

We carry out this method by first making 1 point to NULL. This is done by curr->next=prev and then we without the next node we will not be
able to reach 2 think about it cuz our curr->next has been shifted to prev. Thats the main reason for using the next node.

So after the above operation we move prev to curr and curr=next and use the above mentioned formula.

*/
    ListNode* reverseList(ListNode* head) {
        if(!head)return NULL;
        ListNode* prev,*curr,*next;
        prev=NULL,curr=head;
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }