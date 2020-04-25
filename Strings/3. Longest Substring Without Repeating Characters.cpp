Two pointers:
We will use two pointers and hash table to solve this problem. We keep storing the non repeating elements in a hash table.
As soon as we encounter a repeating element we will increment the l pointer till the rpeating elements value in the hash is 0.
We simulatneously cache the maximum.
Lets assume
s = "abcabcbb"
     ^
     |
    l,r

as a value in the hash is 0 we increment r as well as the hash value   map[a] = 1
as b value in the hash is 0 we increment r as well as the hash value   map[b] = 1
as c value in the hash is 0 we increment r as well as the hash value   map[c] = 1
Now when we encounter a again we move the left pointer until hash[a] = 0.

We keep repeating the above steps and caching in the maximum value.
Here the answer is 3

    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        int l=0,r=0,ans=0;
        while(l<=r&&r<s.length())
        {
            if(map[s[r]]==0)
            {
                map[s[r]]++;
                ans=max(ans,r-l+1);
                r++;
            }
            else
            {
                map[s[l]]--;
                l++;
            }
        }
        return ans;
    }
