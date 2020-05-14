#include<iostream>
#include<vector>

using namespace std;
int partitionSort(vector<int> &arr, int start, int end) {
    // Quick sort
    int pivot = arr[end];
    int pIndex = start;
    for (int i=start; i<end; i++) {
        if (arr[i]<=pivot) {
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[pIndex], arr[end]);
    return pIndex;
}

void quickSort(vector<int> &arr, int start, int end) {
    if (start<end) {
        int partitionIndex = partitionSort(arr, start, end);
        quickSort(arr, start, partitionIndex-1);
        quickSort(arr, partitionIndex+1, end);
    }
}

// Complete the maximumToys function below.
int main() {
    vector<int> prices = {1, 12, 5,111, 200 ,1000 ,10};
    int k = 50;
    quickSort(prices, 0, prices.size()-1);
    int j = 0;
    for (int i=0; i<prices.size(); i++) {
        if ((j+prices[i])>k) {
            
            return 0;
        }
        j+=prices[i];
    }
    return -1;
}
