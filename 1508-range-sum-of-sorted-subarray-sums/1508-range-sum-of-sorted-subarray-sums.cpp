class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
       const int MOD = 1e9 + 7;
        vector<int> subarray_sums;

        // Step 1: Compute all non-empty continuous subarray sums
        for (int i = 0; i < n; ++i) {
            int current_sum = 0;
            for (int j = i; j < n; ++j) {
                current_sum += nums[j];
                subarray_sums.push_back(current_sum);
            }
        }

        // Step 2: Sort the sums in non-decreasing order
        sort(subarray_sums.begin(), subarray_sums.end());

        // Step 3: Calculate the sum of the elements from index left to right
        long long result = 0;
        for (int i = left - 1; i < right; ++i) {
            result = (result + subarray_sums[i]) % MOD;
        }

        return result; 
    }
};