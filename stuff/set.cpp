#include<vector>
#include<set>
#include<iostream>

using namespace std;

// Complete the sockMerchant function below.
int main() {
    vector<int> ar = {10, 20, 20, 10, 10, 30, 50, 10, 20};
    int n = 9;

    set<int> checkPairs;
    int pairs = 0;
    
    for (int i=0; i<ar.size(); i++) {
        if ((checkPairs.empty()) || (checkPairs.find(ar[i]) == checkPairs.end())) {
            checkPairs.insert(ar[i]);
            cout << ar[i] << endl;
        } else {
            checkPairs.erase(ar[i]);
            pairs++;
        }
    }
    cout << pairs << endl;
    return pairs;
}