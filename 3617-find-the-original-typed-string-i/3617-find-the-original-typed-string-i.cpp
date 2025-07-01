class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length();
        int result = 1; 

        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && word[j] == word[i]) {
                ++j;
            }
            int len = j - i;
            if (len > 1) {
                result += (len - 1); 
            }
            i = j;
        }

        return result;
    }
};