
    Solution 1:- O(n)
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        if(nums.size()==0)return {-1,-1};
        int l=0,r=nums.size()-1;
        while(l<=r)
        {
            if(nums[l]==target && nums[r]==target)
            {
                ans.push_back(l);
                ans.push_back(r);
                return ans;
            }
            else if(nums[l]!=target && nums[r]!=target)
                l++,r--;
            else if(nums[l]==target && nums[r]!=target)
                r--;
            else
                l++;
        }
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
    
    Solution 2:-O(logn)
        vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int l=0,r=nums.size()-1,result=INT_MAX;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(nums[m]==target)
            {
                result=m;
                r=m-1;
            }
            else if(nums[m]<target) l=m+1;
            else r=m-1;
        }
        ans.push_back(result!=INT_MAX?result:-1);
        l=0,r=nums.size()-1;
        result=INT_MAX;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(nums[m]==target)
            {
                result=m;
                l=m+1;
            }
            else if(nums[m]<target) l=m+1;
            else r=m-1;
        }
        ans.push_back(result!=INT_MAX?result:-1);
        return ans;
    }
  If you want to learn stl there are a good number of stl functions that this problem can be solved with.
  Solution 3:-

        vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0||binary_search(nums.begin(),nums.end(),target)==0)return {-1,-1};
        int left=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int right=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        return {left,right-1};
    }

  Solution 4:-
        vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        if(find(nums.begin(),nums.end(),target)-nums.begin()>=nums.size())ans.push_back(-1);
        else
            ans.push_back(find(nums.begin(),nums.end(),target)-nums.begin());
        reverse(nums.begin(),nums.end());
        if(find(nums.begin(),nums.end(),target)-nums.begin()>=nums.size())ans.push_back(-1);
        else
            ans.push_back(nums.size()-1-(find(nums.begin(),nums.end(),target)-nums.begin()));
        return ans;
    }