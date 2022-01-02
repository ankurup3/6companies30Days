// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
    int count=1;
    string res="";
    int n = src.length();
    for(int i=0;i<n;i++) {
        if(src[i]!=src[i+1]) {
            res+=src[i];
            res+=to_string(count);
            count=1;
        }
        else count++;
    }
    return res;
  //Your code here 
}     
 
