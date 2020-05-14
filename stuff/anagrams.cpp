#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;
// Class with 26 possibilities (26 letters) to count
class el {
    public:
        vector<int> count;
        el() {
            count.assign(26, 0);
        }
        
};

int main() {
    string s = "kkkk";
    // Index indicates the size of anagram (1 = 1 letter, 2 = 2 letters)
   unordered_map<int, vector<el>> counts;
   for (int i=0; i<s.size(); i++) {
       el countSet;
       // For the first element, don't need to go to the last position
       int r = s.size()-((i==0) ? 1 : i);
       for (int j=0; j<r; j++) {
           int x = s[i+j]%26;
           countSet.count[s[i+j]%26]++;
           counts[j+1].push_back(countSet);
       }
   }
   vector<el>::iterator base;
   int total = 0;
   for (int i=1; i<=s.size(); i++) {
       for (auto c: counts[i]) {
           cout << "T" << endl;
       }
   }
   cout << "Fim" << endl;
}