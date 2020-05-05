/*
I will using bfs and brute force solution.
This solution was suprisingly fast.
We are going to do our standard bfs traversal :-
First I store the wordlist in a set.
We push the begin word into the queue and start traversing.
I start process the string present in a queue and i check if i remove one letter from that string is it present on the set or not.
If so i push the word into the queue and delete the word from the set so that i don visit it again.
I do this until i reach the end word.
If i dont i return 0.
*/
    int ladderLength(string b, string e, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(b);
        int count=0;
        s.erase(b);
        while(!q.empty())
        {
            int n=q.size();
            count++;
            for(int i=0;i<n;i++)
            {
                string word=q.front();
                q.pop();
                if(word==e)return count;
                 for(int j=0;j<(int)word.size();j++)
                {
                    char ch=word[j];
                    for(int k=0;k<26;k++)
                    {
                        word[j]='a'+k;
                        if(s.find(word)!=s.end())
                        {
                            q.push(word);
                            s.erase(word);
                        }
                    }
                    word[j]=ch;
                }
            }
        }
        return 0;
    }
