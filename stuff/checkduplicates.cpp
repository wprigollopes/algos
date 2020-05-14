#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool checkDuplicates(string text) {
    unordered_map<char, int> check;
    for (int i=0; i<text.length(); i++) {
        check[tolower(text[i])]++;
        if (check[text[i]]>1) {
            return false;
        }
    }
    return true;
}

// O(nk) complexity where n is size of the array and k is the max number of keys in the text 
int main() {
    vector<string> terms;
    terms = {"Anaconda", "Ana", "girafa", "auto", "credo", "carroça"};
    for (auto term: terms) {
        if (checkDuplicates(term)) {
            cout << term << " has no duplicates..." << endl;
        } else {
            cout << term << " has duplicates..." << endl;
        }
    }
    return 0;
}