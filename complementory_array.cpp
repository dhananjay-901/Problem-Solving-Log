class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int> diff(2 * limit + 2, 0);
        int n = nums.size();
        for (int i = 0; i < n / 2; ++i) {
            int a = nums[i];
            int b = nums[n - 1 - i];
            diff[2] += 2;
            diff[2 * limit + 1] -= 2;
            int low = min(a, b) + 1;
            int high = max(a, b) + limit;
            diff[low] -= 1;
            diff[high + 1] += 1;
            int sum = a + b;
            diff[sum] -= 1;
            diff[sum + 1] += 1;
        }

        int res = n, curr = 0;
        for (int i = 2; i <= 2 * limit; ++i) {
            curr += diff[i];
            res = min(res, curr);
        }
        return res;
    }
};