class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        set<int> seq;
        for (auto& num : nums)
            seq.insert(num);
        auto it = seq.begin();
        int currlen = 1, maxlen = 1, prev = *it;
        ++it;
        for (; it != seq.end(); ++it) {
            if (*it - prev == 1)
                maxlen = max(maxlen, ++currlen);
            else
                currlen = 1;
            prev = *it;
        }
        return maxlen;
    }
};
