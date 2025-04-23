class Solution {
public:
    int countLargestGroup(int n) {
        int count[37] = {}; 

        for (int i = 1; i <= n; ++i) {
            int sum = 0, x = i;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            count[sum]++;
        }

        int maxSize = 0, groups = 0;
        for (int i = 0; i <= 36; ++i) {
            if (count[i] > maxSize) {
                maxSize = count[i];
                groups = 1;
            } else if (count[i] == maxSize) {
                groups++;
            }
        }

        return groups;
    }
};
