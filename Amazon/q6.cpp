//link to the question: https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> res;
        deque<int> d;
        int start=0,end=0;
        while(end<n) {
            while(d.size() && arr[end]>d.back()) 
                d.pop_back();
            d.push_back(arr[end]);
            if(end-start+1<k) end++;
            else if(end-start+1 == k) {
                res.push_back(d.front());
                if(d.front()==arr[start])
                    d.pop_front();
                start++;
                end++;
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
