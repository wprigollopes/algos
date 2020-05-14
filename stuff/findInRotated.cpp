#include<vector>
#include<stdlib.h>

using namespace std;

int binarySearchRotated(vector<int>&A, int x) {
    int n = A.size();
    int high = n;
    int low = 0;

    while (low<high) {
        int mid = (high - low) / 2;
        if (A[mid]<x) {
            low = mid+1;
        } else if (A[mid]>=x) {
            
        }
    }
}

int main() {
    vector<int> A = {12,14,18,21,3,6,8,9};


}