class Solution {
public:
    bool valid(map<char, unsigned>& scount, map<char, unsigned>& tcount) {
        for (auto it = tcount.begin(); it != tcount.end(); ++it)
            if (scount[it->first] < it->second)
                return false;
        return true;
    }
    string minWindow(string& s, string& t) {
        map<char, unsigned> scount, tcount;
        for (char& c : s)
            ++scount[c];
        for (char& c : t)
            ++tcount[c];
        if (s.empty() || t.empty() || !valid(scount, tcount))
            return "";
        scount.clear();
        unsigned l = 0, r = 0;
        string result = s;
        while (r < s.size()) {
            while (r < s.size() && !valid(scount, tcount))
                scount[s[r++]]++;
            while (valid(scount, tcount)) {
                if (r - l < result.length())
                    result = string(s.begin() + l, s.begin() + r);
                scount[s[l++]]--;
            }
        }
        return result;
    }
};
