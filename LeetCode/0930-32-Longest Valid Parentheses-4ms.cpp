class Solution {
public:
    template <class InputIt, class T>
    int maxLen(InputIt first, InputIt last, T&& val) {
        int left = 0, right = 0, maxlen = 0;
        while (first != last) {
            if (*first++ == val)
                ++left;
            else {
                ++right;
                if (left == right)
                    maxlen = max(maxlen, left + right);
                if (left < right)
                    left = right = 0;
            }
        }
        return maxlen;
    }
    int longestValidParentheses(string& s) {
        return max(maxLen(s.begin(), s.end(), '('), maxLen(s.rbegin(), s.rend(), ')'));
    }
};
