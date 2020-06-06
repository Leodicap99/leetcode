class Solution {
public:
    int max_area=-1;
    void find(vector<int> arr)
    {
        if(arr.size()<1)return;
        stack<int> st;
        int area,top,i=0;
        while(i<arr.size())
        {
            if(st.empty()||arr[i]>=arr[st.top()])
                st.push(i++);
            else
            {
                top=st.top();
                st.pop();
                area=arr[top]*(st.empty()?i:i-st.top()-1);
                max_area=max(max_area,area);
            }
        }
        while(!st.empty())
        {
                 top=st.top();
                st.pop();
                area=arr[top]*(st.empty()?i:i-st.top()-1);
                max_area=max(max_area,area);
        }
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()<1)return 0;
        int n=matrix.size(),m=matrix[0].size();
        vector<int> t(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='0')t[j]=0;
                else 
                    t[j]+=(matrix[i][j]-'0');
            }
            find(t);
        }
        return max_area==-1?0:max_area;
    }
};
