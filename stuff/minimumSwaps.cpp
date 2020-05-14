#include<iostream>
#include<vector>

using namespace std;
int main() {
    int s = 5;
    vector<int> a = {2, 3, 4, 1, 5};
    int numSwaps = 0;
    int swap = 0;
    for (int i=0; i<s; i++) {
        if (a[i] != i+1) {
            for (int j=i+1; j<s; j++) {
                if (a[j] == i+1) {
                    swap = a[i];
                    a[i] = a[j];
                    a[j] = swap;
                    numSwaps++;
                    break;
                }
            }
        }
    }
    return numSwaps;
}
