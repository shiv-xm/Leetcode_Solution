class Solution {
public:
    int maxDifference(string s, int k) {
        int ans = INT_MIN;

        for (const auto& [a, b] : getPermutations()) {
            vector<vector<int>> minDiff(2, vector<int>(2, INT_MAX / 2));
            vector<int> prefixA{0};
            vector<int> prefixB{0};
            for (int l = 0, r = 0; r < s.length(); ++r) {
                prefixA.push_back(prefixA.back() + (s[r] == a ? 1 : 0));
                prefixB.push_back(prefixB.back() + (s[r] == b ? 1 : 0));
                while (r - l + 1 >= k && prefixA[l] < prefixA.back() &&
                       prefixB[l] < prefixB.back()) {
                    minDiff[prefixA[l] % 2][prefixB[l] % 2] =
                        min(minDiff[prefixA[l] % 2][prefixB[l] % 2],
                            prefixA[l] - prefixB[l]);
                    ++l;
                }
                ans = max(
                    ans,
                    (prefixA.back() - prefixB.back()) -
                        minDiff[1 - prefixA.back() % 2][prefixB.back() % 2]);
            }
        }

        return ans;
    }

private:
    vector<pair<char, char>> getPermutations() {
        vector<pair<char, char>> permutations;
        for (const char a : "01234")
            for (const char b : "01234")
                if (a != b)
                    permutations.emplace_back(a, b);
        return permutations;
    }
};