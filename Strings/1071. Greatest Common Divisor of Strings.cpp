/*
The way to tackle it is find the gcd of the two string sizes and return the substring from 0 to the gcd number.
But before doing this we have to see if the unique alphabets of each of the strings are matching.
*/
    string gcdOfStrings(string str1, string str2) {
        unordered_set<char> s1,s2;
        for(char &ch:str1)
        {
            if(s1.find(ch)==s1.end())
            s1.insert(ch);
        }
        for(char &ch:str2)
        s2.insert(ch);
        if(s1.size()!=s2.size())return "";
        return str1.substr(0, gcd(str1.size(), str2.size()));
    } 