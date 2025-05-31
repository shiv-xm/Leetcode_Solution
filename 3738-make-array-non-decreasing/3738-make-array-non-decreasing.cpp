class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {

        int size = 0, prev = -1;

        for(auto num : nums) {
            if(num >= prev) {
                prev = num;
                size++;
            }
        }

        return size;
    }
};