class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return {};
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=0;i<2*n;i++)
        {
            while(!st.empty() && nums[st.top()]<nums[i%n])
            {
                ans[st.top()]=nums[i%n];
                st.pop();
            }
            st.push(i%n);
        }
        return ans;
    }
};
