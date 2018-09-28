#include "headers.h"

struct Solution {
public:
    int countPrimes(int n) {
    	int count = n;
    	vector<bool> prime(n, true);
        for (int i = 4; i < n; ++i)
        	if (!(i % 2) || !(i % 3))
	    		if (prime[i]) {
	    			prime[i] = false;
	    			--count;
				}
    	for (int i = 6; i < sqrt(n); i += 6)
    		for (int k = i - 1; k <= i + 1; k += 2)
    			if (prime[k])
	    			for (int j = k * k; j < n; j += k)
	    				if (prime[j]) {
	    					prime[j] = false;
	    					--count;
						}
    	return max(0, count - 2);
    }
}

int main() {
	Solution sol;
	cout << sol.countPrimes(0) << endl;
	cout << sol.countPrimes(1) << endl;
	cout << sol.countPrimes(2) << endl;
	cout << sol.countPrimes(3) << endl;
	cout << sol.countPrimes(4) << endl;
	cout << sol.countPrimes(5) << endl;
	cout << sol.countPrimes(6) << endl;
	cout << sol.countPrimes(7) << endl;
	cout << sol.countPrimes(8) << endl;
	cout << sol.countPrimes(9) << endl;
	cout << sol.countPrimes(10) << endl;
	cout << sol.countPrimes(10000) << endl;
	return 0;
}


