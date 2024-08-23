class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
         deque<pair<int, int>> dq;
        int maxVal = INT_MIN;

        for (const auto& point : points) {
            int x = point[0], y = point[1];

            // Remove elements from the front of deque that fall outside the window
            while (!dq.empty() && x - dq.front().second > k) {
                dq.pop_front();
            }

            // Calculate equation value and update maximum
            if (!dq.empty()) {
                maxVal = max(maxVal, dq.front().first + y + x);
            }

            // Maintain the deque with potential candidates
            while (!dq.empty() && dq.back().first <= y - x) {
                dq.pop_back();
            }
            dq.push_back({y - x, x});
        }

        return maxVal;
    }
};
