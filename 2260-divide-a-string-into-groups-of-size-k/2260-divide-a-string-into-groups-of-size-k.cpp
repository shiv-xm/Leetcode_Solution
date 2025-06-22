class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        int grps = (n + k - 1) / k;
        vector<string> res(grps);
        for (int i = 0; i < grps; i++) {
            string grp;
            for (int j = 0; j < k; j++) {
                int idx = i * k + j;
                if (idx < n) {
                    grp += s[idx];
                } else {
                    grp += fill;
                }
            }
            res[i] = grp;
        }

        return res;
    }
};