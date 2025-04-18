class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string str = countAndSay(n - 1); 
        string result = "";
        int len = str.length();

        for (int i = 0; i < len; i++) {
            int count = 1;
            while (i < len - 1 && str[i] == str[i + 1]) {
                count++;
                i++;
            }
            result += to_string(count) + str[i];
        }

        return result;
    }
};
