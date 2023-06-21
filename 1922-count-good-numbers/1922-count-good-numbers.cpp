class Solution {
private:
    const int MOD = 1e9 + 7;

    long long powFunction(long long x, long long n) {
        if (n == 0) {
            return 1;
        }
        
        long long half = powFunction(x, n / 2);
        long long ans = half*half;
        ans %= MOD;
        
        if (n % 2 == 1) {
            ans *= x;
            ans %= MOD;
        }
        
        return ans;
    }

public:
    int countGoodNumbers(long long n) {
        long long odd = n / 2;
        long long even = n / 2 + n % 2;
        return (powFunction(5, even) * powFunction(4, odd)) % MOD;
    }
};
