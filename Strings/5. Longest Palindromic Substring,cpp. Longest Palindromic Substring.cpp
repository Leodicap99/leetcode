    

    string longestPalindrome(string s) {
       int maxlen = 0, start=0;
        for(int i = 0;i < s.size();++i) {
            int left = i, right = i;
            while(s[right+1] == s[left]) {//Skip same char in the middle
                right++;
                i++;
            }
            while(left -1 >= 0 && right + 1 < s.size() && s[right+1] == s[left-1]) {//Handle expand
                left--;
                right++;
            }
            if(right-left+1 > maxlen) {//record max pos
                maxlen = right-left+1;
                start = left;
            }
        }
        return s.substr(start, maxlen);
    }