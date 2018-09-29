/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if (!intervals.empty()) {
            sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b) {
                return a.start < b.start;
            });
            int start, end, i = 0, count = 0;
            for (; i < intervals.size() - 1; ++i) {
                if (intervals[i].end >= intervals[i + 1].start) {
                    intervals[i + 1].start = intervals[i].start;
                    if (intervals[i].end > intervals[i + 1].end)
                        intervals[i + 1].end = intervals[i].end;
                }                    
                else
                    result.push_back(intervals[i]);
            }
            result.push_back(intervals[i]);
        }
        return result;        
    }
};
