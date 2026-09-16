class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;
        int total = n + k - 1;
        int choose = 2 * k;

        if (choose > total) return 0;

        auto power = [&](long long base, long long exp) {
            long long res = 1;
            base %= MOD;
            while (exp > 0) {
                if (exp & 1) res = (res * base) % MOD;
                base = (base * base) % MOD;
                exp >>= 1;
            }
            return res;
        };

        auto modInverse = [&](long long a) {
            return power(a, MOD - 2);
        };

        long long numerator = 1;
        long long denominator = 1;

        for (int i = 0; i < choose; ++i) {
            numerator = (numerator * (total - i)) % MOD;
            denominator = (denominator * (i + 1)) % MOD;
        }

        return (numerator * modInverse(denominator)) % MOD;
    }
};