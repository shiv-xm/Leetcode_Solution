class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend()); 
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        if (nums.size() < 3)
            return nums[0];  

        return nums[2];  
    }
};
