class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        int l = 0, r = 0, sum = 0, count = 0;
        while (r < nums.size()) {
            sum += (nums[r] % 2);  

            while (sum > k) {
                sum -= (nums[l] % 2);
                l++;
            }

            count += (r - l + 1);  
            r++;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
