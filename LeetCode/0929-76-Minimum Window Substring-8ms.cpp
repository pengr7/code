class Solution {
public:
    
    // sliding window approach
    string minWindow(string& s, string& t) {
        
        // l, r: left index and right index of the sliding window
        // lres, rres: left index and right index of the result
        // scount: number of unique characters in s that satisfies the requirement
        // tcount: number of unique characters in t
        // len: minimum window length
        int l = 0, r = 0, lres = 0, rres = 0, scount = 0, tcount = 0, len = INT_MAX;
        
        if (!s.empty() && !t.empty() && s.size() >= t.size()) {
            
            // the number of each character in s and t
            vector<int> shash(128, 0), thash(128, 0);
            
            for (char& c : t) {
                if (!thash[c])
                    ++tcount;
                ++thash[c];
            }
            
            // expand the window till it contains all characters in t
            for (; r < s.length(); r++) {
                if (++shash[s[r]] == thash[s[r]])
                    ++scount;
                
                // contract (shrink) the window till it doesn't contain all characters in t
                for (; scount == tcount; l++) {
                    if (--shash[s[l]] < thash[s[l]])
                        --scount;
                    
                    // if the current window is better, update indexes and length
                    if (r - l + 1 < len) {
                        len = r - l + 1;
                        lres = l;
                        rres = r;
                    }
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(lres, len);
    }
};
