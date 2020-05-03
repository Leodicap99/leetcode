/*
The way to tackle this problem is to use 3 pointers:-
1. Odd pointer
2. Even pointer
3. First Even pointer 
We connect odd pointers to the evens next pointer and the even next pointer to the next odd pointer.
*/
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode* odd=head,*even=head->next,*firsteven=even;
        while(even&&even->next)
        {
            odd->next=odd->next->next;
            even->next=even->next->next;
            odd=odd->next;
            even=even->next;
        }
        odd->next=firsteven;
        return head;
    }
/*
Let us test this code with an example
1->2->3->4->5->6->NULL

odd points to 1 and even points to 2
odd->next=odd->next->next make 1->3
even->next=even->next->next makes 2->4
then we move the odd pointer to 3 and even pointer to 4

then 1->3->5
2->4->6 
then we move the odd pointer to 5 and even pointer to 6
at this point even->next is NULL so we break
*/