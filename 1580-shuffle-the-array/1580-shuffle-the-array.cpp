class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        for (int i = 0; i < 2 * n; i++) {
            if (i % 2 == 0) {
                res.push_back(nums[i / 2]);       
            } else {
                res.push_back(nums[n + i / 2]);    
            }
        }
        return res;
    }
};
