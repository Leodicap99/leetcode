class Solution {
public:
    string decodeString(string s) {
        stack<int> digit;
        stack<string> ans_st;
        string ans;
        int i=0;
        while(i<s.size())
        {
            if(isdigit(s[i]))
            {
                int count=0;
                while(isdigit(s[i]))
                {
                    count=count*10+(s[i]-'0');
                    i++;
                }
                digit.push(count);
            }
            else if(s[i]=='[')
            {
                ans_st.push(ans);
                ans="";
                i++;
            }
            else if(isalpha(s[i]))
            {
                ans+=s[i];
                i++;
            }
            else
            {
                int c=digit.top();
                digit.pop();
                string t=ans_st.top();
                ans_st.pop();
                for(int i=0;i<c;i++)t+=ans;
                ans=t;
                i++;
            }
        }
        return ans;
    }
};
