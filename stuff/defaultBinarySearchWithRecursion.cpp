#include<stdio.h>

int binarySearch(int A[], int n, int x) {
    int low = 0;
    int high = n-1;
    while (low<=high) {
        int mid = (low + high) / 2;
        if (A[mid] == x) return mid;
        else if (x < A[mid]) high = mid-1;
        else low = mid+1;
        printf("High %d - Low %d at pos %d - Element at %d\n", high, low, mid, A[mid]);
    }
    return -1;
}

int binarySearchFirst(int A[], int n, int x) {
    int low = 0;
    int high = n-1;
    int result = -1;
    while (low<=high) {
        int mid = (low + high) / 2;
        // We modify this output to recheck the conditions
        if (A[mid] == x) { 
            result = mid; 
            high = mid-1; 
        }
        else if (x < A[mid]) high = mid-1;
        else low = mid+1;
        printf("High %d - Low %d at pos %d - Element at %d\n", high, low, mid, A[mid]);
    }
    return result;
}

int binarySearchLast(int A[], int n, int x) {
    int low = 0;
    int high = n-1;
    int result = -1;
    while (low<=high) {
        int mid = (low + high) / 2;
        // We modify this output to recheck the conditions
        if (A[mid] == x) { 
            result = mid; 
            low = mid+1; 
        }
        else if (x < A[mid]) high = mid-1;
        else low = mid+1;
        printf("High %d - Low %d at pos %d - Element at %d\n", high, low, mid, A[mid]);
    }
    return result;
}

int main() {
    int A[] = {2,3,4,6,7,8,10,10,10,12,14,15,18,29};
     printf("Enter a number to search: ");
    int x;
    scanf("%d", &x);
    printf("Binary search...\n");
    int index = binarySearch(A, sizeof(A)/sizeof(int), x);
    if (index != -1) {
        printf("Number %d found at position %d - DEFAULT binary search\n", x, index);
    } else {
        printf("Number %d not found\n", x);
    }

    int indexFirst = binarySearchFirst(A, sizeof(A)/sizeof(int), x);
    if (indexFirst != -1) {
        printf("Number %d found first at position %d\n", x, index);
    } else {
        printf("Number %d not found\n", x);
    }


    printf("Searching for the last element position: ");
    int indexLast = binarySearchLast(A, sizeof(A)/sizeof(int), x);
    if (indexLast != -1) {
        printf("Number %d found last at position %d\n", x, index);
    } else {
        printf("Number %d not found\n", x);
    }
    if (index != -1) {
        printf("The array contains %d elements with value %d\n", (indexLast-indexFirst+1), x);
    } else {
        printf("Element not found");
    }
}