/*
We will first start by taking k=2.
1->2->3
2->7->11
We proceed by picking the the smallest pointer value and moving the pointer of the linked list forward.
The same procedure will follow for k increasing. We will be greedily picking the smallest value and moving the corresponding pointer forward.
But the problem is for k=2 we can check the smaller value of the two just by using < or > symbol.
But if k is large lets say 1 million using such a technique will take years to compute.
We will have to using a smarter data structure to solve this question.
Think of a data structure which will take all the values and will be able to give the smallest value in the least time.
a min heap would be of the right choice.

1. We will push all the first pointer of each of the linked list into the heap.
2. We must also move the pointer of that list forward.
3. Then we start linkig all the smallest nodes and get our solution.
Remember that heaps are in the form of trees but for simplicity i have represent it like this. 

Let k=3
1->8->11
2->3->7
3->6->16
          |         |
          |    1    |
          |    2    |
          |    3    |  <-----min heap storing the values of the first with top value as 1
          |_________| 

       ans=   1->

          |         |
          |    2    |
          |    3    |
          |    8    |  <-----1 is p0poed out and the next pointer points to 8 which is pushed to the heap with top element as 2.
          |_________| 

       ans=   1->2->

          |         |
          |    3    |
          |    3    |
          |    8    |  <-----2 is p0poed out and the next pointer points to 3 which is pushed to the heap with top element as 3.
          |_________| 


          ans = 1->2->3


          Similarly the approach follows and u get the final result.

*/
    struct comp
    {
      bool operator()(const ListNode* a,ListNode* b)
      {
          return a->val>b->val;
      }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comp> pq;
        for(auto x:lists)
        {
            if(x)pq.push(x);
        }
        if(pq.empty())return NULL;
        ListNode* result=pq.top();
        pq.pop();
        if(result->next)pq.push(result->next);
        ListNode* t=result;
        while(!pq.empty())
        {
            t->next=pq.top();
            pq.pop();
            t=t->next;
            if(t->next)pq.push(t->next);
        }
        return result;
    }