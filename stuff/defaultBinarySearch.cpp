#include<stdio.h>



int main() {
    int A[] = {2,3,4,6,7,8,10,12,14,15,18,29};
     printf("Enter a number to search: ");
    int x;
    scanf("%d", &x);
    int index = binarySearch(A, (sizeof(A)/sizeof(int)), x);
    if (index != -1) {
        printf("Number %d found at position %d\n", x, index);
    } else {
        printf("Number %d not found\n", x);
    }
}