class Solution {
public:
    vector<string> wordBreak(string& s, vector<string>& wordDict) {
        dict.insert(wordDict.begin(), wordDict.end());
        return wordBreakRec(s);
    }
private:    
    unordered_set<string> dict;
    unordered_map<string, vector<string>> mp;
    vector<string> wordBreakRec(string& s) {
        vector<string> res;
        if (!s.empty()) {
            if (mp.count(s))
                return mp[s];
            if (dict.count(s))
                res.push_back(s);
            for (int i = 0; i <= s.size(); ++i) {
                string left = s.substr(0, i), right = s.substr(i);
                if (dict.count(left))
                    for (string& temp : wordBreakRec(right))
                        res.push_back(left + " " + temp);
            }
            mp[s] = res;
        }
        return res;
    }
};
