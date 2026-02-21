#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {

    if (intervals.empty()) return {};

    sort(intervals.begin(), intervals.end(), 
        [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

    vector<vector<int>> merged;
    vector<int> prev = intervals[0];

    for (int i = 1; i < intervals.size(); ++i) {
        vector<int> interval = intervals[i];

        if (interval[0] <= prev[1]) {
            prev[1] = max(prev[1], interval[1]);
        } 
        else {
            merged.push_back(prev);
            prev = interval;
        }
    }

    merged.push_back(prev);
    return merged;
}

int main() {

    vector<vector<int>> intervals = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}
    };

    vector<vector<int>> result = mergeIntervals(intervals);

    cout << "Merged Intervals:\n";
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    return 0;
}