#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long count = 0;

        for (int i = 0; i < n; ++i) {
            int left =
                lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) -
                nums.begin();
            int right =
                upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) -
                nums.begin();
            count += (right - left);
        }

        return count;
    }
};
