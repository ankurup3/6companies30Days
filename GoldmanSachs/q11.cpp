//question link: https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/#
// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int a[n+1]={0};
        int res[2];
        int count=0;
        for(int i=0;i<n;i++) {
            a[arr[i]]+=1;
        }
        for(int i=1;i<n+1;i++) {
            if(count==2) break;
            if(a[i]==0) {
                res[1]=i;
                count++;
            }
            if(a[i]==2) {
                res[0]=i;
                count++;
            }
        }

        int *ans = new int[2];
        ans[0]=res[0];
        ans[1]=res[1];
        return ans;
        // code here
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends