class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        int l = 0, count = 0;
        long long sum = 0;

        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];
            while (sum > goal && l <= r) {
                sum -= nums[l++];
            }
            count += (r - l + 1);
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};
