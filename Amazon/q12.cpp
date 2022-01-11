//link to the question: 

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        string res="";
        while(n) {
            char c = 'A'+(n-1)%26;
            res+=c;
            n=(n-1)/26;
        }
        reverse(res.begin(), res.end());
        return res;
        // your code here
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
  // } Driver Code Ends