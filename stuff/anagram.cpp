#include<iostream>
#include<vector>
#include<unordered_map>
//
// Check if two strings are anagrams
// Using unordered map to check if every element are contained in both strings 
// O(n) time | O(nm) space
//

using namespace std;
int main() {
    string a = "cde";
    string b = "abc";
    unordered_map<char, int> check;
    int s = max(a.size(), b.size());
    for (int i=0; i<s; i++) {
        if (i<a.size()) {
            check[a[i]]++;
        }
        if (i<b.size()) {
            check[b[i]]--;
        }
    }
    int letters = 0;
    for (auto c: check) {
       if (c.second == 0) letters++; 
    }
    return letters;
return 0;
}
