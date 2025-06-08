class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;  
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        return power(x, N);
    }

private:
    double power(double x, long long n) {
        if (n == 0) return 1;
        if (n % 2 == 0)
            return power(x * x, n / 2);
        else
            return x * power(x, n - 1);
    }
};
