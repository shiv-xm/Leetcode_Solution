class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for (char ch : num) {
            while (!st.empty() && k > 0 && st.top() > ch) {
                st.pop();
                k--;
            }
            st.push(ch);
        }

        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());

        int i = 0;
        while (i < result.size() && result[i] == '0') {
            i++;
        }

        result = result.substr(i); 
        return result.empty() ? "0" : result;
    }
};
