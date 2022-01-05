//link to the question: https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0,right=0,sum=0;
        int ans = INT_MAX;
        int n = nums.size();
        while(right<n) {
            sum+=nums[right];
            while(left<=right && sum>=target) {
                ans = min(ans, right-left+1);
                sum-=nums[left];
                left++;
            }
            right++;
        }
        if(ans==INT_MAX) return 0;
        else return ans;
    }
};