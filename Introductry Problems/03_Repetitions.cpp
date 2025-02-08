// You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is to find the longest repetition in the sequence. This is a maximum-length substring containing only one type of character.
// Input
// The only input line contains a string of n characters.
// Output
// Print one integer: the length of the longest repetition.

// Example
// Input:

// ATTCGGGA
// Output:

// 3

#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n = s.size();
    if(n==1)cout<<1;
    else{
        int i =0;
        vector<int>cnt(26,0);
        while(i<n-1){
            int count = 1;
            while(s[i] == s[i+1]){
                count++;
                i++;
            }
            cnt[s[i]-'A'] = max(cnt[s[i]-'A'],count);
            i++;
        }
        sort(cnt.begin(),cnt.end());
        cout<<cnt[25];
    }
    return 0;
}