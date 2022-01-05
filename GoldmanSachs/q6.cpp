//link to the question: https://leetcode.com/problems/greatest-common-divisor-of-strings/submissions/

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        //like Euclid's algo for gcd of numbers
        if(str1.length() < str2.length() ) {
            return gcdOfStrings(str2,str1);
        } 
        if(str2.empty()) {
            return str1;
        }
        string  str="";
        if( str1.substr(0, str2.length())!= str2 ) return str;
            return gcdOfStrings (str1.substr(str2.length()), str2 );
    }
};