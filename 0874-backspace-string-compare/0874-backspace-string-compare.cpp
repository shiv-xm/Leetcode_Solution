class Solution {
public:
    string process(string str) {
        stack<char> st;
        for (char ch : str) {
            if (ch == '#') {
                if (!st.empty()) st.pop();
            } else {
                st.push(ch);
            }
        }
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end()); 
        return result;
    }
    bool backspaceCompare(string s, string t) {
        return process(s) == process(t);
    }
};
