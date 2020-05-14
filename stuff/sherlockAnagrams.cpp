#include<iostream>
#include<map>
#include<algorithm>
#include<string>

using namespace std;

map<string, int> stringMap;

int main() {
    string s="abcd";
    map<string, int> stringMap;
    // Get the length
    int len = s.size();
    // Traverse string
    for (int i=0; i<len; i++) {
      // And get all possible substrings
      for (int j=1; j+i-1<len; j++) {
          // Get the term
          string term = s.substr(i, j);
          // Order
          sort(term.begin(), term.end());
          // Add to string mapping, the string quantity;
          stringMap[term]++;
      }
    }
    long long ans = 0; // New variable for the quantity
    // Traverse the map created
    for (map<string, int>::iterator it=stringMap.begin(); it != stringMap.end(); ++it) {
          ans += (long long)(it->second) * (it->second-1) /2;
    }
    return ans;
}

}