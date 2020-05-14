#include<iostream>
#include<vector>

using namespace std;


vector<vector<int>> powersetHelper(vector<int> array, int idx) {
    if (idx <0) {
        return vector<vector<int>> {{}};
    }
    int ele = array[idx];
    vector<vector<int>> subsets = powersetHelper(array, idx-1);
    int length = subsets.size();
    for (int i=0; i<length; i++) {
        vector<int> currentSubset = subsets[i];
        vector<int> newSubset = currentSubset;
        newSubset.push_back(ele);
        subsets.push_back(newSubset);
    }
    return subsets;
}

vector<vector<int>> powerset(vector<int> array) {
    return powersetHelper(array, array.size()-1);
}


int main() {
    vector<int> elements = {1,2,3};
    vector<vector<int>> subsets = powerset(elements);
    return 0;
}
