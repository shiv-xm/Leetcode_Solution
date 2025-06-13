class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 1) return true;      // 3^0 = 1
        if (n <= 0 || n % 3 != 0) return false; // base cases
        return isPowerOfThree(n / 3); // recursive call
    }
};
