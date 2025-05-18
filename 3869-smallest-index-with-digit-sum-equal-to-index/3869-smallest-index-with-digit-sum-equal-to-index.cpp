class Solution {
public:
    int digit_sum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            if(i == digit_sum(nums[i])){
                return i;
            }
        }
        return -1;
    }
};