/*
Given an integer array arr, in one move you can select a palindromic subarray arr[i], arr[i+1], ..., arr[j] where i <= j, and remove that subarray from the given array. 
Note that after removing a subarray, the elements on the left and on the right of that subarray move to fill the gap left by the removal.

Return the minimum number of moves needed to remove all numbers from the array.
*/

class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        int n = arr.size();
        
        // dp[left][right] = the min move for arr[left]...arr[right] (both included).
        // the max number of move is n.
        vector<vector<int>> dp(n, vector<int>(n, n));
        
        // handle edge situation: subarray size == 1
        for(int i = 0; i < n; i++) { dp[i][i] = 1; }
        
        // handle edge situation: subarray size == 2
        for(int i = 0; i < n - 1; i++) { dp[i][i + 1] = arr[i] == arr[i + 1] ? 1 : 2; }
        
        // for subarray size >= 3:
        for(int size = 3; size <= n; size++) {
            for(int left = 0, right = left + size - 1; right < n; left++, right++) {
                
                // if arr[left] == arr[right], then the two number: arr[left] and arr[right] can be
                // removed when the last move of subarray arr[left + 1:right - 1]
                if(arr[left] == arr[right]) {
                    dp[left][right] = dp[left + 1][right - 1];
                }
                
                // or, if we cannot remove arr[left] and arr[right] in one move (the last move),
                // the subarray arr[left:right] must can be split into two subarrays
                // and remove them one by one.
                for(int mid = left; mid < right; mid++) {
                    dp[left][right] = min(dp[left][right], dp[left][mid] + dp[mid + 1][right]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
