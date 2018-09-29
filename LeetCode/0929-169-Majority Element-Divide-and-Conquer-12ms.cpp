class Solution {
public:
    int count(vector<int>& nums, int num, int lo, int hi) {
        int res = 0;
        while (lo <= hi)
            res += nums[lo++] == num;
        return res;
    }
    int majorityElementRec(vector<int>& nums, int lo, int hi) {
        if (lo == hi)
            return nums[lo];
        int mid = (lo + hi) / 2;
        int left = majorityElementRec(nums, lo, mid), right = majorityElementRec(nums, mid + 1, hi);
        if (left == right)
            return left;
        int cleft = count(nums, left, lo, mid), cright = count(nums, right, mid + 1, hi);
        return cleft > cright ? left : right;
    }
    int majorityElement(vector<int>& nums) {
        return majorityElementRec(nums, 0, nums.size() - 1);
    }
};
