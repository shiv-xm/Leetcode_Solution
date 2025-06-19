class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        int half = n / 2;
        unordered_map<int, int> mp;

        for (auto &w : candyType) {
            mp[w]++;  
        }
        return min((int)mp.size(), half);
    }
};
