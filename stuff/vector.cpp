#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n; // Number of arrays
    int q; // Number of queries
    vector<vector<int>> el;
    cin >> n;
    cin >> q;
    for (int i=0; i<n; i++) {
        int s;
        cin >> s;
        vector<int> row;
        for (int j=0; j<s; j++) {
            int cellValue;
            cin >> cellValue;
            row.push_back(cellValue);
        }
        el.push_back(row);
    }
    for (int i=0; i<q; i++) {
        int posi, posj;
        cin >> posi;
        cin >> posj;
        cout << el[posi][posj] << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

