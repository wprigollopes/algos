#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main() {
    // As a min problem, begin with n+1 possitibilities and INT_MAX and, the first possibility is 0
    int value = 6;
    // Options
    vector<int> coins = {1,2,4};
    // Possibilities
    vector<int> possibilities(value+1, INT_MAX);
    possibilities[0] = 0;
    // Here, we have the traversal
    for (int c=0; c<coins.size(); c++) {
        int coin = coins[c];
        for (int p=coin; p<=value; p++) {
            possibilities[p] = min(possibilities[p], possibilities[p-coin] == INT_MAX ? possibilities[p-coin] :  1+possibilities[p-coin]);
        }
    }
    cout << (possibilities[value] != INT_MAX ? possibilities[value] : -1) << endl;
    return 0;
}


//         
// c= 1  0 1 2 3 4 5 6
//
// n     0 1 2 3 4 5 6