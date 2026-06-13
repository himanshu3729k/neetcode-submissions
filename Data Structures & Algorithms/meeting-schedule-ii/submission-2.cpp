/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n=intervals.size();

        if(n<=1) return n;

        sort(intervals.begin(),intervals.end(), [](Interval& x, Interval& y){
            return x.start < y.start;
        });

        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto& v:intervals){
            if(!pq.empty() && pq.top() <= v.start) pq.pop();

            pq.push(v.end);
        }

        return pq.size();
    }
};
