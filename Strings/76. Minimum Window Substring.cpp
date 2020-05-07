/*
We are going to use a two pointer approach to solve this.

The idea here is that 
1. We will store the characters of t in a map lets say mapt.
2. We will have two pointers l and r.
3. Whille we traverse through s we check if the character is found in mapt If so we will store the character into another hash map lets say maps.
4. If the mapped charcter freq of s is less than or equal to mapt we increment a letter counter variable that will let us know when we have reached the t string size.
5. We try to find the smallest substring which contains all chracters in t using a while loop.

 S = "ADOBECODEBANC" and T = "ABC"

 mapt
 A -> 1
 B -> 1
 C -> 1

 We keep l=0 and traverse S with r.

 "ADOBECODEBANC"
  ^
  |
  r 

as A is present in t we use another map for s to store A into the hashmap

maps
A->1
we have another variable lettercounter that keeps track of the size.
lettercounter
1

 "ADOBECODEBANC"
   ^
   |
   r
As D isnt present in t we just continue traversing.

 "ADOBECODEBANC"
    ^
    |
    r
Same as the above step.

 "ADOBECODEBANC"
     ^
     |
     r   
As B is present in map t

maps
A->1
B->1

lettercounter
2

 "ADOBECODEBANC"
      ^
      |
      r
 "ADOBECODEBANC"
       ^
       |
       r
C is present in mapt

maps
A->1
B->1
C->1

lettercounter
3
as lettercount is equal to t.size We will try shortening the substring

As there is only 1 A in s and t and A is the first character we cant reduce the size.

So out best bet currently would the substring
ans=  "ADOBEC"

We continue traversing and checking the above steps.

*/
    string minWindow(string s, string t) {
        unordered_map<char,int> map1;
        unordered_map<char,int> map2;
        int check=INT_MAX;
        string result;
        for(char &ch:t)map1[ch]++;
        int slow=0,fast=0,lettercounter=0;
        for(;fast<s.length();fast++)
        {
            char ch=s[fast];
            if(map1.find(ch)!=map1.end())
            {
                map2[ch]++;
            if(map2[ch]<=map1[ch])
                lettercounter++;
            }
            if(lettercounter>=t.length())
            {
                while(map1.find(s[slow])==map1.end()||map2[s[slow]]>map1[s[slow]])
                {
                    map2[s[slow]]--;
                    slow++;
                }
                if(fast-slow+1<check)
                {
                    check=fast-slow+1;
                    result=s.substr(slow,check);
                }
            }
        }
        return result;
    }