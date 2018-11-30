class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        long long time = timeSeries.size() * (long long)duration;
        for (int i = 1; i < timeSeries.size(); ++i) {
            int overlap = timeSeries[i-1] + duration - timeSeries[i];
            if (overlap > 0)
                time -= overlap;
        }
        return (int)time;
    }
};
