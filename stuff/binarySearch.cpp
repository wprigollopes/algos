#include<iostream>
#include<vector>

using namespace std;

int binarySearch(vector<int> arr, int val) {
    int left = 0;
    int right = arr.size()-1;
    
    while (left<right) {
        int middle = left + (right-left)/2;
        if (arr[middle] == val) {
            return middle;
        }
        if (arr[middle]>val) {
            right = middle-1;
        } else {
            left = middle+1;
        }
    }
    return -1;
}

int main() {
    // Posição:        0 1 2 3 4 5  6  7  8  9   10  11  12  13
    vector<int> arr = {1,2,4,7,8,22,51,75,99,102,220,496,958,1938};
    int pos = binarySearch(arr, 8);
    cout << pos << endl;
    return 0;
}
