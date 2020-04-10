// File created on video: https://www.youtube.com/watch?v=EoplHg1SIFA&list=PLrwFkFaGJb6DYbOFOvSPo3cm8DJv83OWN&index=2&t=161s
#include<iostream>
#include<vector>

using namespace std;

int binarySearch(vector<int> arr, int toSearch) {
    int left = 0;
    int right = arr.size()-1;

    while (left<=right) {
        int middle = left + (right-left)/2;
        if (arr[middle] == toSearch) {
            return middle;
        }
        if (arr[middle]>toSearch) {
            right = middle-1;
        } else {
            left = middle+1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 2, 5, 20, 24, 49, 54, 55, 91};
    int toSearch = 48;
    int pos = binarySearch(arr, toSearch);
    if (pos == -1) {
        cout << "Value not found" << endl;
    } else {
        cout << "The position is: " << pos << endl;
    }
    return 0;
}
