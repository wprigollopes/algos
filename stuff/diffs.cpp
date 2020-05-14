#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>

using namespace std;

int main() {
    string s = "aabbcd";
    unordered_map<char, int> counts;
    for (int i=0; i<s.size(); i++) {
        counts[s[i]]++;
    }
    int last = 0;
    int diffs = 0; 
    
    return 0;
    //return "YES";
}