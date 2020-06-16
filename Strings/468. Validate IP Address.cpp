class Solution {
public:
    vector<string> split(string s,char ch)
    {
        vector<string> ans;
        string block;
        istringstream iss(s);
        while(getline(iss,block,ch))
            ans.push_back(block);
        return ans;
    }
    bool isvalidIPv6(string s)
    {
        if(count(s.begin(),s.end(),':')!=7)return false;
        vector<string> parts=split(s,':');
        if(parts.size()!=8)return false;
        for(string &str:parts)
        {
            if(str.size()>4||str.empty())return false;
            for(char ch:str)
            {
                if(!isdigit(ch) && (!isalpha(ch) || toupper(ch)>'F'))return false;
            }
            
        }
        return true;
    }
    bool isvalidIPv4(string s)
    {
        if(count(s.begin(),s.end(),'.')!=3)return false;
        vector<string> parts=split(s,'.');
        if(parts.size()!=4)return false;
        for(string &str:parts)
        {
            if(str.size()>3||(str.size()>1 &&str[0]=='0')||str.empty())
                return false;
            for(char ch:str)
                if(!isdigit(ch))return false;
            if(stoi(str)>255)return false;
        }
        return true;
    }
    string validIPAddress(string IP) {
        return isvalidIPv4(IP)?"IPv4":(isvalidIPv6(IP)?"IPv6":"Neither");
    }
};
