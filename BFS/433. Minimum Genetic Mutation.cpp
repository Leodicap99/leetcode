    int minMutation(string start, string end, vector<string>& bank) {
        vector<char> dir={'A','C','G','T'};
        unordered_set<string> s(bank.begin(),bank.end()); //help us with find and erase for a gene
        queue<string> q;
        q.push(start);
        int count=0;
        s.erase(start);   //if start is present in the set we erase to avoid looping
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                string gene=q.front();
                q.pop();
                if(gene==end)return count;
                for(int j=0;j<gene.size();j++)
                {
                    char ch=gene[j];
                    for(int k=0;k<dir.size();k++)    //use our dur array to modify our gene
                    {
                        gene[j]=dir[k];
                        if(s.find(gene)!=s.end())
                        {
                            q.push(gene);
                            s.erase(gene);
                        }
                    }
                    gene[j]=ch;
                }
            }
            
            count++;
        }
        return -1;
    }