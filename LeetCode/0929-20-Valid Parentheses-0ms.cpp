class Solution {
public:
    bool isValid(string s) {
        stack<char> v;
        map<char, char> mp = {{'}', '{'}, {']', '['}, {')', '('}};
        for (char c : s) {
            if (mp.find(c) == mp.end())
                v.push(c);
            else if (!v.empty() && mp[c] == v.top())
                v.pop();
            else
                return false;
        }
        return v.empty();
    }
};
