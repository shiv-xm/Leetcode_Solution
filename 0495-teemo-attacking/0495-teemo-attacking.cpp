class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int total = 0;
    int n = timeSeries.size();

    for (int i = 0; i < n - 1; ++i) {
        total += min(duration, timeSeries[i + 1] - timeSeries[i]);
    }

    if (n > 0) total += duration;  

    return total;
}

};