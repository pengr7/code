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
        map<int, int> numline;
        for (auto& interval:intervals) {
            ++numline[interval.start];
            --numline[interval.end];
        }
        vector<Interval> result;
        int start, end, count = 0;
        for (auto it = numline.begin(); it != numline.end(); ++it) {
            if (!count)
                start = it -> first;
            count += it -> second;
            if (!count) {
                end = it -> first;
                result.push_back(Interval(start, end));
            }                
        }
        return result;
    }
};
