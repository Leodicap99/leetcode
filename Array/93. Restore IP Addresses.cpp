class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string temp;
        for(int a=1;a<=3;a++)
            for(int b=1;b<=3;b++)
                for(int c=1;c<=3;c++)
                    for(int d=1;d<=3;d++)
                    {
                        if(a+b+c+d==s.length())
                        {
                            int A=stoi(s.substr(0,a));
                            int B=stoi(s.substr(a,b));
                            int C=stoi(s.substr(a+b,c));
                            int D=stoi(s.substr(a+b+c,d));
                            if(A<=255 && B<=255 && C<=255 && D<=255)
                                if((temp=to_string(A)+'.'+to_string(B)+'.'+to_string(C)+'.'+to_string(D)).length()==s.length()+3)
                                    ans.push_back(temp);
                        }  
                    }
        return ans;
    }
};


class Solution {
public:
    vector<string> ans;
    void dfs(string s,int index,string path,int count)
    {
        if(count>4)return;
        if(count==4 && index>=s.length())
        {
            path.pop_back();
            ans.push_back(path);
            return;
        }
        for(int i=1;i<4 && index+i<=s.length();i++)
        {
            string t=s.substr(index,i);
            if((i!=1 && t[0]=='0')||(stoi(t)>=256))continue;
            dfs(s,index+i,path+t+'.',count+1);
            
        }
    }
    vector<string> restoreIpAddresses(string s) {
        dfs(s,0,"",0);
        return ans;
    }
};
