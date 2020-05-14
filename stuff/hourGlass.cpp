#include<iostream>
#include<vector>

using namespace std;
int main() {
    vector<vector<int>> arr;
    arr = {{-1,-1, 0, -9, -2, -2},
{-2, -1, -6, -8, -2, -5},
{-1, -1, -1, -2, -3, -4},
{-1, -9, -2, -4, -4, -5},
{-7, -3, -3, -2, -9, -9},
{-1, -3, -1, -2, -4, -5}};
    long totalSum = 0;
    long maxSum = 0;
    int maxI;
    int maxJ;
    int r = arr.size();
    int c = arr[0].size();
    for (int i=1; i<r-1; i++) {
        for (int j=1; j<c-1; j++) {
            cout << i << " - " << j << " - " << arr[i-1][j-1] << "|" << arr[i-1][j] << "|" << arr[i-1][j+1] << "|" << arr[i][j] << "|" << arr[i+1][j-1] << "|" << arr[i+1][j] << "|" << arr[i+1][j+1] << "---" << arr[i-1][j-1]+arr[i-1][j]+arr[i-1][j+1] + arr[i][j] + arr[i+1][j-1]+arr[i+1][j]+arr[i+1][j+1] << endl;
            totalSum = 
            arr[i-1][j-1]+arr[i-1][j]+arr[i-1][j+1] + // first row and 3 columns of clock
            arr[i][j] + // Second row and middle column of clock
            arr[i+1][j-1]+arr[i+1][j]+arr[i+1][j+1]; // Third row and 3 columns of clock
            if (totalSum>maxSum) {
                maxI = i;
                maxJ = j;
                maxSum = totalSum;
            }
        }
    }
    cout << maxSum << endl;
    return maxSum;
}