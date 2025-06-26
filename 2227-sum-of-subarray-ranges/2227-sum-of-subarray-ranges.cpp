class Solution {
public:
    vector<long long> findPSE(vector<int> nums) {
        int n = nums.size();
        stack<int> st;
        vector<long long> result(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty()) result[i] = st.top();
            st.push(i);
        }
        return result;
    }

    vector<long long> findNSE(vector<int> nums) {
        int n = nums.size();
        stack<int> st;
        vector<long long> result(n, n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            if (!st.empty()) result[i] = st.top();
            st.push(i);
        }
        return result;
    }

    vector<long long> findPGE(vector<int> nums) {
        int n = nums.size();
        stack<int> st;
        vector<long long> result(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if (!st.empty()) result[i] = st.top();
            st.push(i);
        }
        return result;
    }

    vector<long long> findNGE(vector<int> nums) {
        int n = nums.size();
        stack<int> st;
        vector<long long> result(n, n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            if (!st.empty()) result[i] = st.top();
            st.push(i);
        }
        return result;
    }

    long long findmax(vector<long long> nge, vector<long long> pge, vector<int> nums) {
        long long maxi = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            long long contri = (i - pge[i]) * 1LL * (nge[i] - i);
            maxi += contri * nums[i];
        }
        return maxi;
    }

    long long findmin(vector<long long> nse, vector<long long> pse, vector<int> nums) {
        long long mini = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            long long contri = (i - pse[i]) * 1LL * (nse[i] - i);
            mini += contri * nums[i];
        }
        return mini;
    }

    long long subArrayRanges(vector<int>& nums) {
        vector<long long> pse = findPSE(nums);
        vector<long long> nse = findNSE(nums);
        vector<long long> pge = findPGE(nums);
        vector<long long> nge = findNGE(nums);

        long long maxi = findmax(nge, pge, nums);
        long long mini = findmin(nse, pse, nums);

        return maxi - mini;
    }
};
