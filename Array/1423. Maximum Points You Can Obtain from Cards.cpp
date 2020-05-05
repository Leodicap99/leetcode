   Source:- https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/discuss/597883/Javascript-and-C%2B%2B-solutions
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int sum=0,ans=0;
        deque<int> dq;
        for(int i=n-k;i<n;i++)
        {
            sum+=cardPoints[i];
            dq.push_back(cardPoints[i]);
        }
        ans=sum;
        for(int i=0;i<k;i++)
        {
            sum-=dq.front();
            dq.pop_front();
            sum+=cardPoints[i];
            ans=max(ans,sum);
        }
        return ans;
    }
