class Solution {
public:
    bool checkValidString(string s) {
        int min = 0;
        int max = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                min++;
                max++;
            } else if (s[i] == ')') {
                min--;
                max--;
            } else { // s[i] == '*'
                min--;      // treat '*' as ')'
                max++;      // treat '*' as '('
            }

            if (min < 0) min = 0;
            if (max < 0) return false; // too many ')'
        }

        return (min == 0);
    }
};
