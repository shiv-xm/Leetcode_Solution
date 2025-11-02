class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long p = 100000;
        int n = nums.size();

        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });

        long long a = nums[n-1], b = nums[n-2];

        if ((a > 0 && b > 0) || (a < 0 && b < 0)) {
            return a * b * p;
        } else {
            return a * b * (-p);
        }
    }
};
