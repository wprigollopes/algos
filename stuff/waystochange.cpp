#include<iostream>
#include<vector>

using namespace std;

int main() {
    int change = 10;
    vector<int> coins = {1,5,10,25};

    vector<int> ways(change+1, 0);
    ways[0] = 1;
    for (int c=0; c<coins.size(); c++) {
        for (int amount=coins[c]; amount<=change; amount++) {
            ways[amount] += ways[amount-coins[c]];
        }
    }
    return ways[ways.size()-1];
}