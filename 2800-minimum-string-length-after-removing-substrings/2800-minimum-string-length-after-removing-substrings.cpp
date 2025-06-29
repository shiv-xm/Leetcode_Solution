class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for (char ch : s) {
            if (!st.empty()) {
                char top = st.top();
                if ((top == 'A' && ch == 'B') || (top == 'C' && ch == 'D')) {
                    st.pop();
                    continue;
                }
            }
            st.push(ch);
        }
        return st.size();
    }
};