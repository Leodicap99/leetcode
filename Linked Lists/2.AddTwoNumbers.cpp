/*The example might seem confusing due to the wordingIts simple to understand.Let me demonstrate
2->4->3 + 5->6->4 = 7->0->8
notice that the addition goes from left to right and so is the carry propagation.
Thus our algorithm should satisfy the above condition. What we cn do is
Step 1: Store the sum as carry which is intially set to 0.
Step 2: Add the numbers as we traverse through both the Linked List.
Step 3: Thus sum=h1->val+h2->val+carry.
Step 4: Then we store the carry value as sum/10.


l1 = [2,4,3]   ,   l2 = [5,6,4]  
      ^                  ^
      |                  |
     *l1                *l2


carry = 0
sum=carry=0
 
sum = l1->val + l2->val = 0 + 2 + 5 = 7    carry=sum/10=0 sum = sum%10 = 7

ans=[7]
  
 similarly we keep proceeding

sum = 4 + 6 + 0 =10 + 7 = 17.......carry = sum/10 = 1  sum = sum%10 = 0

ans=[7,0]

sum = 4 + 3 + 1 = 8        carry = sum/10 = 0  sum = sum%10 = 8

ans=[7,0,8]

Edge Cases:

1. If the final carry is still there (>0) add it to the list.
      */

   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(0);
        ListNode* newhead=dummy;
        int sum,carry=0;
        while(l1||l2)
        {
            sum=carry;
            if(l1)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            dummy->next=new ListNode(sum%10);
            carry=sum/10;
            dummy=dummy->next;
        }
        if(carry)dummy->next=new ListNode(carry);
        return newhead->next;
    }
