class Solution {
public:
    string longestNiceSubstring(string s) {
        if (s.length() < 2) return "";

        unordered_set<char> st(s.begin(), s.end());

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (st.count(tolower(ch)) && st.count(toupper(ch))) continue;

            string left = longestNiceSubstring(s.substr(0, i));
            string right = longestNiceSubstring(s.substr(i + 1));

            return left.length() >= right.length() ? left : right;
        }

        return s;
    }
};
