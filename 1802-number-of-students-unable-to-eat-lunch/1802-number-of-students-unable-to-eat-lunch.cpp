class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        stack<int> st;
        for (int s : students) q.push(s);
        for (int i = sandwiches.size() - 1; i >= 0; i--) {
            st.push(sandwiches[i]);
        }
        int cnt = 0;

        while (!q.empty() && cnt < q.size()) {
            if (q.front() == st.top()) {
                q.pop();
                st.pop();
                cnt = 0; 
            } else {
                q.push(q.front());
                q.pop();
                cnt++; 
            }
        }
        return q.size(); 
    }
};