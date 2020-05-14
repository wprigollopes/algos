#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int main() {
    vector<int> expenditure = {2, 3, 4, 2, 3 ,6, 8, 4, 5};
    vector<int> orderedExpenditure;
    int d = 5;
    int s = expenditure.size();
    bool odd = ((d%2) == 0) ? true : false;
    int middle = ((float)d/2);
    int warnings = 0;
    orderedExpenditure = vector<int>(expenditure.begin(), expenditure.begin()+d);
    quickSort(orderedExpenditure, 0, d-1);
    for (int i=0; i<s-d; i++) {
        double ceilExp;
        if (odd) {
            ceilExp = (orderedExpenditure[middle] + orderedExpenditure[middle+1])/2;
        } else {
            ceilExp = orderedExpenditure[middle];
        }
        cout << expenditure[d+i] << " - " << (ceilExp*2) << endl;
        if (expenditure[d+i]>=(ceilExp*2)) {
            warnings++;
        }
    }
    return warnings;
}