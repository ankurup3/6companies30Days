//link to the question: https://practice.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    set<int> nut;
	    set<int> bolt;
	    for(int i=0;i<n;i++) {
	        nut.insert(nuts[i]);
	        bolt.insert(bolts[i]);
	    }
	    auto it=nut.begin();
	    for(int i=0;i<n;i++) {
	        if(nut.find(bolts[i])!=nut.end() && bolt.find(bolts[i])!=bolt.end()) {
	            nuts[i]=*it;
	            bolts[i]= *it;
	        }
	        it++;
	    }
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends