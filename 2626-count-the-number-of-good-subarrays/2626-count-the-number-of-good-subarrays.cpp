class Solution {
 public:
  long long countGood(vector<int>& nums, int k) {
    long ans = 0;
    int pairs = 0;
    unordered_map<int, int> count;

    for (int l = 0, r = 0; r < nums.size(); ++r) {
      
      pairs += count[nums[r]]++;
      while (pairs >= k)
        pairs -= --count[nums[l++]];
     
      ans += l;
    }

    return ans;
  }
};