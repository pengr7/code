class Solution {
public:
    int countPrimes(int n) {
        int count = n;
        vector<bool> prime(n, true);
        for (int i = 4; i < n; i += 2) {
            prime[i] = false;
            --count;
        }
        for (int i = 9; i < n; i += 6) {
            prime[i] = false;
            --count;
        }
        for (int i = 5; i < sqrt(n); i += 6)
            for (int j = i; j <= i + 2; j += 2)
                if (prime[j])
                    for (int k = j * j; k < n; k += j)
                        if (prime[k]) {
                            prime[k] = false;
                            --count;
                        }
        return max(0, count - 2);
    }
};
