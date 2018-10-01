class Solution {
public:
    
    // dynamic programming solution
    // space complexity: O(n)
    // time complexity: O(mn), assuming the average size of words in dictionary is negligible
    //     where m is the size of dictionary, n is the size of string
    bool wordBreak(string& s, vector<string>& wordDict) {
        
        // use hash to speed up the cost of querying the dictionary to constant time
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        
        // dp[i] stores if string(s.begin(), s.begin() + i) is breakable
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        
        // string(s.begin(), s.begin() + i) is breakable if and only if
        //     it consists of a breakable substring and a word in the dictionary
        // we iterate thru the dict and get the result of dp[i]
        for (int i = 0; i <= s.size(); ++i)
            for (string& word : wordDict) {
                int wlen = word.length(), wfrom = i - wlen;
                if (wfrom >= 0 && dp[wfrom] && dict.find(s.substr(wfrom, wlen)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        return dp[s.size()];
    }
};
