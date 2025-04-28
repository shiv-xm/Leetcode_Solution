class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visit;
        while (visit.find(n) == visit.end()) {
            visit.insert(n);
            n = getNext(n);
            if (n == 1) {
                return true;
            }
        }

        return false;
    }

private:
    int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int digit = n % 10;
            totalSum += digit * digit;
            n /= 10;
        }
        return totalSum;
    }
};