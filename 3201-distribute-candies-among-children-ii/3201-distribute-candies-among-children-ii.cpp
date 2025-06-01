class Solution {
public:
    long long nCr2(long long x) {
        if (x < 2) return 0;
        return x * (x - 1) / 2;
    }

    long long distributeCandies(int n, int limit) {
        long long total = nCr2(n + 2);
        long long sub1 = nCr2(n - limit + 1);
        long long sub2 = nCr2(n - 2 * limit);
        long long sub3 = nCr2(n - 3 * limit - 1);

        return total - 3 * sub1 + 3 * sub2 - sub3;
    }
};