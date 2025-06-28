class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,maxlen=0;
        int Zeros=0;
        while(r<nums.size()){
            if(nums[r]==0)Zeros++;
            while(Zeros>k){
                if(nums[l]==0)Zeros--;
                l++;
            }
            if(Zeros<=k){
                maxlen=max(r-l+1,maxlen);
            }
            r++;
        }
        return maxlen;
    }
};