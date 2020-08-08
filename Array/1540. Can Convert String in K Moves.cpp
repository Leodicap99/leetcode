class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.size()!=t.size())return false;
        vector<int> v(27,0);
        for(int i=0;i<(int)s.size();i++)
        {
            if(s[i]==t[i])continue;
            int x=t[i]-s[i];
            if(x<0)x+=26;
            if(x>k||x+v[x]>k)return false;
            v[x]+=26;
        }
        return true;
    }
};
