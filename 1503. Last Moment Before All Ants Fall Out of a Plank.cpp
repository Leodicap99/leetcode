class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxL = 0, minR = n;
        if (!left.empty())  maxL = *max_element (left.begin(), left.end());
        if (!right.empty()) minR = *min_element (right.begin(), right.end());
        return max (maxL, n - minR);
    }
};
