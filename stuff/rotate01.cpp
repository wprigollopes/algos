#include<iostream>
#include<stdio.h>
void leftRotate(int arr[], int d, int n) {
    for (int i=0; i<d; i++) {
        int temp = arr[0], j;
        for (int j=0; j<n-1; j++) {
            arr[j] = arr[j+1];
        }
        arr[j] = temp;
    }
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr) / sizeof(arr[0]);

    leftRotate(arr, 2, n);
  //  std::cout << arr[0] << std::endl;

    return 0;
}