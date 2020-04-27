/*
We will be emplying a dummy node which points to some arbitrary value in the heap section of the memory.
the dummy->next will point to head.
We will have two pointers one that points to the head and the other that points to dummy.Thus making  first pointer one node ahead of the 
second pointer.
Our main goal here is to reach the n-1th pointer (We thus use 2 pointers for simplicity and reduce in conditions)
while(n--) ptr1=ptr1->next we keep moving.
then use another while loop that keeps moving ptr1 and ptr 2 to the next node.
Once the 1st pointer points to NULL the second pointer will point to n-1 .
Then all u have to do is ptr2->next=ptr->next->next

Let head = 1->2->3->4->5 and n = 2
           ^
           |
      dummy next=head
ptr1 points to head
	1->2->3->4->5    (n=2)
    ^
    |
   ptr1	 
    1->2->3->4->5    (n=1)
       ^
       |
     ptr1

    1->2->3->4->5    (n=0)
          ^
          |
         ptr1
Now the second pointer comes to use

 1->2->3->4->5    (ptr1!=NULL)  ptr2 points to dummy
^         ^
|         |
ptr2     ptr1

1->2->3->4->5    (ptr1!=NULL)
^           ^
|           |
ptr2       ptr1

1->2->3->4->5    (ptr==NULL)
   ^         ^
   |         |
  ptr2      ptr1

  thus now we point ptr2->next=ptr2->next->next

  1->2->4->5 ---->ANSWER!!
  */

      ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)return NULL;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* ptr1=head,*ptr2=dummy;
        while(n--)ptr1=ptr1->next;
        while(ptr1)
        {
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        ptr2->next=ptr2->next->next;
        return dummy->next;
    }