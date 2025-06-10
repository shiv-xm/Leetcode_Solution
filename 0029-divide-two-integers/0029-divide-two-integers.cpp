class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor)
            return 1;

        bool isPositive = (dividend < 0) == (divisor < 0);

        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long ans = 0;

        while (a >= b) {
            int q = 0;
            while (a >= (b << (q + 1))) q++;
            ans += (1LL << q);
            a -= (b << q);
        }

        if (ans > INT_MAX)
            return isPositive ? INT_MAX : INT_MIN;

        return isPositive ? ans : -ans;
    }
};
