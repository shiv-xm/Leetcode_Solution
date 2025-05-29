class Solution {
public:
    long long calculateTotalHours(vector<int>& piles, int hourly) {
        long long totalH = 0;
        for (int pile : piles) {
            totalH += (pile + hourly - 1LL) / hourly; 
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int answer = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalH = calculateTotalHours(piles, mid);

            if (totalH <= (long long)h) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1; 
            }
        }

        return answer;
    }
};
