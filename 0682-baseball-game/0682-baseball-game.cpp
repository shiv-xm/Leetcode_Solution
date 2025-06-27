class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        
        for (string op : operations) {
            if (op == "C") {
                if (!st.empty()) st.pop();
            } else if (op == "D") {
                if (!st.empty()) st.push(2 * st.top());
            } else if (op == "+") {
                int top1 = st.top(); st.pop();
                int top2 = st.top();
                st.push(top1);  // push back top1 as we popped it
                st.push(top1 + top2);
            } else {
                st.push(stoi(op));
            }
        }
        
        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }
        
        return sum;
    }
};
