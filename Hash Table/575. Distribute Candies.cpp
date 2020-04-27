/*
The algorithm to solve this pretty simple:
return the minimum of the diffrent types of candies and candies.size()/2
*/
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> s;
        for(int i=0;i<candies.size();i++)
            s.insert(candies[i]);
        if(s.size()>candies.size()/2)return candies.size()/2;
        else 
            return s.size();
    }
