    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()<1)return 0;
        stack<int> st;
        int i=0,area,max_area=-1;
        while(i<heights.size())
        {
            if(st.empty()||heights[i]>=heights[st.top()])
                st.push(i++);
            else
            {
                int top=st.top();
                   st.pop();
                   area=heights[top]*(st.empty()?i:i-st.top()-1);
                   max_area=max(max_area,area);
            }
        }
        while(!st.empty())
        {
            int top=st.top();
                   st.pop();
                   area=heights[top]*(st.empty()?i:i-st.top()-1);
                   max_area=max(max_area,area);
        }
        return max_area;
    }
