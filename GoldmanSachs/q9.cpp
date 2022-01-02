//link to the question: https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1#

// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S) {
        stack<int> s;
        string ans="";
        for(int i=0;i<=S.length();i++) {
            s.push(i+1);
            if(i==S.length() || S[i]=='I') {
                while(!s.empty()) {
                    ans+=to_string(s.top());
                    s.pop();
                }
            }
        }
        return ans;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends