class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxlen = 0;
        unordered_set<int> seq(nums.begin(), nums.end());
        for (auto& num : nums) {
            int l = 0, r = 0;
            seq.erase(num);
            while (seq.find(--l + num) != seq.end())
                seq.erase(num + l);
            while (seq.find(++r + num) != seq.end())
                seq.erase(num + r);
            maxlen = max(maxlen, r - l - 1);
        }
        return maxlen;
    }
};
