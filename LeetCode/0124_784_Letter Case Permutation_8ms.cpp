class Solution {
public:
    vector<string> letterCasePermutation(const string S) {
    	// extract alphabetic letters and their corresponding locations
        string alphastr;
        vector<unsigned> alphaloc;
        for (unsigned i = 0; i < S.size(); ++i)
        	if (isalpha(S[i])) {
        		alphastr += tolower(S[i]);
        		alphaloc.push_back(i);
			}
		
		// get binary numbers
		vector<vector<int>> bins(1 << alphastr.size());
		for (int num = 0; num < 1 << alphastr.size(); ++num) {
			vector<int> bin(alphastr.size(), 0);
			for (unsigned i = 0; i < alphastr.size(); ++i)
				if (num & 1 << i)
					bin[alphastr.size() - i - 1] = 1;
			bins[num] = bin;
		}
		
		// get result
    	vector<string> res(bins.size(), S);
        for (unsigned i = 0; i < bins.size(); ++i)
        	for (unsigned j = 0; j < alphastr.size(); ++j)
        		res[i][alphaloc[j]] = bins[i][j] ? toupper(res[i][alphaloc[j]]) : tolower(res[i][alphaloc[j]]);
		return res;
    }
};
