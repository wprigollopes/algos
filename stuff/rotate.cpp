#include<iostream>
#include<vector>

using namespace std;
int main() {
    int n = 15;
    int r = 13;
    int i = 0;
    vector<int> arr = {33, 47, 70, 37, 8, 53, 13, 93, 71, 72, 51, 100, 60, 87, 97};
    if (r>n) {
        r = n%r;
    }
    for (int i=1; i<r; i++) {
        arr.push_back(arr[0]);
        arr.erase(arr.begin());
    }
    return arr;
}