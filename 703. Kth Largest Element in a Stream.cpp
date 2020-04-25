This is a typicaly heap question.The biggere question is what heap do we use/
While both heaps would yield the correct answer we want to produce an anwer with the brtter complexity.
The answer would be a minheap

Let num = [3,4,5,10,2] k=3

        |  3  |
        |  4  | <---------This would be the minheap after storing the first 3 element in it with the smallest elemeyt at the top.
        |__5__|              
Now the what we do is our main goal is to make the kth larget element at the top of the heap so extraction takes o(1)time excluding the heapify time.

We would build the heap by storing the larget k numbers in the heao with the smallest of them at the top yielding the kth 
largest number.
             
        |  4  |
        |  5  | <---------as 10 was greater than the top of the heap (i.e 3) we popped it and stored 10 in it.
        |__10_|   
 Remember Our Goal here is the store the k largest elements into the heap.

        |  4  |
        |  5  | <---------as 2 wasnt greater than heap.top() we just dont do anything.
        |__10_| 

        Thus our final answer is heap.top() -> 4.

     priority_queue<int,vector<int>,greater<int>> minheap;
    int m_k;
    KthLargest(int k, vector<int>& nums) {
        m_k=k;
        for(int x:nums)add(x);
    }
    
    int add(int val) {
        if(minheap.size()<m_k)minheap.push(val);
        else
        {
            if(val>minheap.top())
            {
                minheap.pop();
                minheap.push(val);
            }
        }
        return minheap.top();
    }