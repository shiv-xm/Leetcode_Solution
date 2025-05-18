class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<tuple<int, int, int>> arr;
        for (int i = 0; i < n; ++i) {
            arr.emplace_back(digitSum(nums[i]), nums[i], i);
        }
        sort(arr.begin(), arr.end());
        vector<int> indexMap(n);
        for (int i = 0; i < n; ++i) {
            indexMap[get<2>(arr[i])] = i;
        }

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || indexMap[i] == i) continue;

            int cycle_size = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = indexMap[j];
                cycle_size++;
            }

            if (cycle_size > 1) {
                swaps += (cycle_size - 1);
            }
        }

        return swaps;
    }
};
