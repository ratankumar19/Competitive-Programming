#include <bits/stdc++.h> 
using namespace std;  
int countPalindromeSubstrings(char s[]) {
	// Write your code here
	int count = 0;
   // int n = 0;
   // for(int i=0;s[i]!='\0';i++)
    //	n++;
    int n = strlen(s);
    for(int i=0;i<n;i++){
        
        //ODD Substrings which are Palindrome
        int l = i;
        int r = i;
        while (l>=0 && r<n && s[r]==s[l]){
            count++;
            l--;
            r++;
        }
        
        //EVEN Substrings which are Palindrome
        l = i;
        r = i+1;
        while (l>=0 && r<n && s[r]==s[l]){
            count++;
            l--;
            r++;
        }
        
    }
    return count;
}
