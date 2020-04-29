/*
Here the only problem that you will be facing is popmax:
To tackle this we follow this algorithm:
1. We find the maxstack top in our normal stack,
2.When we find that element we pop that element from both the stack.
3.We used a temp stack which pushed elements which were not the maxstack top.
4 While we use the push the temp stack elements back to the normal stack we push it into macstack if it empty or if the element is greater than top to maxstack.
*/
  stack<int> s1,s2;
    void add (int x)
    {
        if(s2.empty()||x>=s2.top())s2.push(x);
    }
    MaxStack() {
        
    }
    
    void push(int x) {
        s1.push(x);
        add(x);
    }
    
    int pop() {
        int x=s1.top();
        s1.pop();
        if(s2.top()==x)s2.pop();
        return x;
    }
    
    int top() {
        return s1.top();
    }
    
    int peekMax() {
        return s2.top();
    }
    
    int popMax() {
        int x=s2.top();
        stack<int> t;
        while(s1.top()!=s2.top())
        {
            t.push(s1.top());
            s1.pop();
        }
        s2.pop();
        s1.pop();
        while(!t.empty())
        {
            s1.push(t.top());
            add(t.top());
            t.pop();
        }
        return x;
    }