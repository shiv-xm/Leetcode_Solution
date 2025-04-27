class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n= nums.size();
        int cnt=0;
        for(int i=0; i<n-2; i++){
            if(nums[i+1]==(nums[i]+nums[i+2])*2){
                cnt++;
            }
        }
        return cnt;
    }
};