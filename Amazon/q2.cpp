//link to the question: https://leetcode.com/problems/longest-mountain-in-array/

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int N = arr.size(), res = 0;
        vector<int> up(N, 0), down(N, 0);
        for (int i = N - 2; i >= 0; --i) if (arr[i] > arr[i + 1]) down[i] = down[i + 1] + 1;
        for (int i = 0; i < N; ++i) {
            if (i > 0 && arr[i] > arr[i - 1]) up[i] = up[i - 1] + 1;
            if (up[i] && down[i]) res = max(res, up[i] + down[i] + 1);
        }
        return res;
    }
};