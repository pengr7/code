class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp = triangle.back();
        for (int level = triangle.size() - 2; level >= 0; --level)
            for (int i = 0; i <= level; ++i)
                dp[i] = min(dp[i], dp[i+1]) + triangle[level][i];
        return dp[0];
    }
};
