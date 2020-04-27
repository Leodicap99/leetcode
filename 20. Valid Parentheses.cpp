/*
I will be using the stack based approach cuz its the easiest to implement if you know the data strucure well.
There are five thing you will have to look for:
1. If the character is any of the opening braces.
2. If the character is an closing braces and the stack top is the corresponding opening braces.
3. If the character is an closing braces and the stack top is n0t the corresponding opening braces.
4. If the character is a closing braces but the stack is empty.
5. After all the checks finally if the stack is empty.

Before looking into th answer just think logically as to how to tacked these five cases.

1. Push it into the stack.
2. Pop out of the stack.
3. return false.
4. return false.
5. If stack is not empty return false.

Finally return true as we have handled all the cases of the test failing.

*/
    bool isValid(string s) {
       if(s.size()==0)return true;
        stack<char> st;
        for(char &ch:s)
        {
            if(ch=='(' || ch=='{' || ch=='[')st.push(ch);
            else
            {
                if(st.empty())return false;
                if(st.top()=='[' &&ch==']')st.pop();
                else if(st.top()=='{' &&ch=='}')st.pop();
                else if(st.top()=='(' &&ch==')')st.pop();
                else return false;
            }
        }
        if(!st.empty())return false;
        return true;
    }