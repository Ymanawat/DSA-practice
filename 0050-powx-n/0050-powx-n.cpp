class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        
        double half = myPow(x, n / 2);
        double result = half * half;

        if (n % 2 != 0) {
            if (n > 0)
                result *= x;
            else
                result *= 1 / x;
        }

        return result;
    }
};
