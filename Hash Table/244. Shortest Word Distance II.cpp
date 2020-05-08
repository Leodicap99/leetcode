/*
The fact that duplicates might exist is what makes this problem a medium and not easy.
We have to somehow find some permutation of the words which gives the shortest distance between 2 words.

We use an unordered_map<int,vector<int>> which sores all the positions where an alphabet occurs and use it to find 
the shortest distance.
*/
    unordered_map<string,vector<int>> map;
    WordDistance(vector<string>& words) {
        for(int i=0;i<words.size();i++)
        {
            map[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int shortest=INT_MAX;
        int i=0,j=0;
        int size1=map[word1].size(),size2=map[word2].size();
        while(i<size1 && j<size2)
        {
            shortest=min(shortest,abs(map[word1][i]-map[word2][j]));
            if(map[word1][i]<map[word2][j])i++;
            else j++;
        }
        return shortest;
    }