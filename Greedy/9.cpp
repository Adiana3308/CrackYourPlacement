#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimalBreakingCost(vector<int> &vertical_cuts, vector<int> &horizontal_cuts) {
    // Sort both vertical and horizontal cuts in descending order
    sort(vertical_cuts.begin(), vertical_cuts.end(), greater<int>());
    sort(horizontal_cuts.begin(), horizontal_cuts.end(), greater<int>());

    int vertical_pieces = 1;   // Initially, 1 vertical piece
    int horizontal_pieces = 1; // Initially, 1 horizontal piece
    int total_cost = 0;

    int v_idx = 0, h_idx = 0;
    
    // Greedily choose the largest cost cut available
    while (v_idx < vertical_cuts.size() && h_idx < horizontal_cuts.size()) {
        if (vertical_cuts[v_idx] > horizontal_cuts[h_idx]) {
            total_cost += vertical_cuts[v_idx] * horizontal_pieces;
            vertical_pieces++;
            v_idx++;
        } else {
            total_cost += horizontal_cuts[h_idx] * vertical_pieces;
            horizontal_pieces++;
            h_idx++;
        }
    }
    
    // If any vertical cuts are left, apply them
    while (v_idx < vertical_cuts.size()) {
        total_cost += vertical_cuts[v_idx] * horizontal_pieces;
        v_idx++;
    }
    
    // If any horizontal cuts are left, apply them
    while (h_idx < horizontal_cuts.size()) {
        total_cost += horizontal_cuts[h_idx] * vertical_pieces;
        h_idx++;
    }

    return total_cost;
}

int main() {
    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int m, n;
        cin >> m >> n;

        vector<int> vertical_cuts(m - 1);
        vector<int> horizontal_cuts(n - 1);

        // Input vertical cuts
        for (int i = 0; i < m - 1; i++) {
            cin >> vertical_cuts[i];
        }

        // Input horizontal cuts
        for (int i = 0; i < n - 1; i++) {
            cin >> horizontal_cuts[i];
        }

        // Calculate minimal cost for this test case
        int result = minimalBreakingCost(vertical_cuts, horizontal_cuts);

        // Output the result
        cout << result << endl;

        // Consume the blank line between test cases (if any)
        if (test_cases > 0) {
            string blank;
            getline(cin, blank);
        }
    }

    return 0;
}
