class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });

        vector<int> chosen;  // store selected numbers

        for (auto &it : intervals) {
            int s = it[0], e = it[1];
            int count = 0;

            // count how many chosen lie inside [s, e]
            for (int x : chosen) {
                if (x >= s && x <= e) count++;
            }

            // already have 2 → OK
            if (count >= 2) continue;

            // if only 1, need to add 1 more (at e)
            if (count == 1) {
                chosen.push_back(e);
            } else { 
                // count == 0 → need two numbers
                chosen.push_back(e - 1);
                chosen.push_back(e);
            }
        }

        return chosen.size();
    }
};
