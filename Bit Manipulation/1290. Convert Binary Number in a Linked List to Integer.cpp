/*
The basic idea to this question is that we keep left shifting the values thats visited during the traversal of the Linked List
head = 1 -> 0 -> 1
let ans = 0
we right shift ans and add the head->val
00 + 1 =1 only
10 + 0 =10
100 + 1 =101 =ans =5
*/

    int getDecimalValue(ListNode* head) {
       int ans=0;
        while(head)                  
        {
            ans<<=1;
            ans|=head->val;
            head=head->next;
        }
        return ans;
    }