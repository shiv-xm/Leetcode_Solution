class Solution {
public:
    string makeGood(string s) {
        stack<char> st;

        for (char c : s) {
            if (!st.empty() && abs(st.top() - c) == 32) {
                st.pop(); 
            } else {
                st.push(c);
            }
        }

        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
