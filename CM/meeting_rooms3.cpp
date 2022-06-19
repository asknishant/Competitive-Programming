//Meeting rooms 3 and calendar 3


class Solution {
public:
    /**
     * @param intervals: the intervals
     * @param rooms: the sum of rooms
     * @param ask: the ask
     * @return: true or false of each meeting
     */
    vector<bool> meetingRoomIII(vector<vector<int>> &calendar, int rooms, vector<vector<int>> &query) {
        // Write your code here.
        sort(calendar.begin(), calendar.end());
        priority_queue<int, vector<int>, greater<>> pq; //min_heap, used to store the end times of the current meetings
        
        vector<vector<int>> not_possible_intervals;
        
        for (const auto &interval : calendar) {
            while (!pq.empty() and pq.top() <= interval[0]) {
                pq.pop();
            }
            pq.push(interval[1]);
            if (pq.size() == rooms) { // rooms are full, after inserting the current interval
                not_possible_intervals.push_back({interval[0], pq.top()}); //will be in increasing order
            }
        }
        
        vector<bool> res;
        for (auto &q : query) {
            int lo = 0, hi = not_possible_intervals.size() - 1;
            int ind = -1;
            while (lo <= hi) {
                int mid = lo + (hi - lo)/2;
                if (not_possible_intervals[mid][1] <= q[0]) {
                    ind = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            if (ind + 1 == not_possible_intervals.size()) res.push_back(true);
            else {
                res.push_back(not_possible_intervals[ind + 1][0] >= q[0] and not_possible_intervals[ind + 1][0] >= q[1]);
            }
        }
        return res;
    }
};
