class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
       stack<int> s;
    int n = nums.size();
    
    for (int i = 0; i < n; ++i) {
        if (s.empty() || nums[i] < nums[s.top()]) {
            s.push(i);
        }
    }
    
    int maxWidth = 0;
    for (int j = n - 1; j >= 0; --j) {
        while (!s.empty() && nums[j] >= nums[s.top()]) {
            maxWidth = max(maxWidth, j - s.top());
            s.pop();
        }
    }
    
    return maxWidth; 
    }
};