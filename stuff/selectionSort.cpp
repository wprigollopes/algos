/* O() */
#include<vector>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

void selectionSort(vector<int>A) {
    int n = A.size();
    for (int i=0; i<n-1;i++) {
        int imin = i;
        for (int j=i+1; j<n; j++) {
            if (A[j] < A[imin]) {
                imin = j;
            }
        }
        int temp = A[i];
        A[i] = A[imin];
        A[imin] = temp;
    }
}

int main() {
    vector<int> A = { 2,5,1,6,3,7,9,6};
    selectionSort(A);
    for (int i=0; i<A.size(); i++) {
        printf("%d - ", A[i]);
    }
}