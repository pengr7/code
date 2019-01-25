class Solution {
public:
	int bitcount(int num) {
		int res = 0;
		while (num) {
			++res;
			num &= num - 1;
		}
		return res;
	}
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (int h = 0; h < 12; ++h)
        	for (int m = 0; m < 60; ++m)
        		if (bitcount(h) + bitcount(m) == num) {
        			string s = to_string(h) + ":";
        			if (m < 10)
        				s += "0";
        			s += to_string(m);
        			res.push_back(s);
				}
		return res;
    }
};
