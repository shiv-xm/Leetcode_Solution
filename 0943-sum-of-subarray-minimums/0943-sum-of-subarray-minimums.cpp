class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n), nse(n);
        stack<int> st;

        // Find Previous Smaller Element (strictly less)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Clear stack for NSE computation
        while (!st.empty()) st.pop();

        // Find Next Smaller Element (strictly less)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Calculate result
        long long total = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            total = (total + (arr[i] * left % mod * right % mod)) % mod;
        }

        return total;
    }
};
