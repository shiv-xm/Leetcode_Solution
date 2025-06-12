class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maxDiff = 0;
        for (int i = 0; i < n; i++) {
            int next = (i + 1) % n; 
            maxDiff = max(maxDiff, abs(nums[i] - nums[next]));
        }
        return maxDiff;
    }
};