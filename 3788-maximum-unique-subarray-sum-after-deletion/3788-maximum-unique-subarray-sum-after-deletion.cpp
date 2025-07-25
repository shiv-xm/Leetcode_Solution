class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum = 0;
        set<int> st;
        int mxNeg = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                st.insert(nums[i]);
            else
                mxNeg = max(mxNeg, nums[i]);
        }
        for (auto val : st) {
            sum += val;
        }
        if (st.size())
            return sum;
        else
            return mxNeg;
    }
};