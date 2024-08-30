class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0);
        if (n == 0) {
            return result;
        }
        result[0] = 0;
        if (n >= 1) {
            result[1] = 1;
        }
        for (int x = 2; x <= n; ++x) {
            if (x % 2 == 0) {
                result[x] = result[x / 2];
            }
            else {
                result[x] = result[x / 2] + 1;
            }
        }
        return result;
    }
};
