//link to the question: https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        int n = nums.size();
        if(n%2!=0) return false;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++) {
            m[nums[i]%k]++;
        }
        for(int i=0;i<n;i++) {
            int rem1 = nums[i]%k;
            if(rem1==0) {
                if(m[rem1]%2!=0) return false;
            }
            else {
                int rem2 = k-rem1;
                if(rem1==rem2 && (m[rem1]%2!=0 || m[rem2]%2!=0) ) return false;
                if(m.find(rem2)==m.end()) return false;
                if(m[rem1]!=m[rem2]) return false;
            }
        }
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends