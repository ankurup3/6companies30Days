//link to the question: https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1/#
// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    set<ull> s;
	    s.insert(1);
	    n-=1;
	    while(n) {
	        auto it = s.begin();
	        ull ugly=*it;
	        s.insert(ugly*2);
	        s.insert(ugly*3);
	        s.insert(ugly*5);
	        s.erase(it);
	        n--;
	    }
	    return *s.begin();
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends