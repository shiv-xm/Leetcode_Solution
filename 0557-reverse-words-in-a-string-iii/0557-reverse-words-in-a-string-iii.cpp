class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int start = 0;

        for (int i = 0; i <= n; i++) {
            // Check for end of word or end of string
            if (i == n || s[i] == ' ') {
                int end = i - 1;
                // Reverse the word using two pointers
                while (start < end) {
                    swap(s[start], s[end]);
                    start++;
                    end--;
                }
                // Move to the start of next word
                start = i + 1;
            }
        }
        return s;
    }
};
