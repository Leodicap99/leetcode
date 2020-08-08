class Solution {
public:
    int minInsertions(string s) {
        int ans=0;
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')st.push(s[i]);
            else if(s[i]==')' && i+1<s.size() && s[i+1]==')')
            {
                if(st.size())st.pop();
                else ans++;
                i++;
            }
            else
            {
                if(st.empty())ans+=2;
                else 
                {
                    ans+=1;
                    st.pop();
                }
            }
        }
        ans+=2*st.size();
        return ans;
    }
};
