#include<iostream>
#include<vector>

using namespace std;
int main() {
    vector<int> c = {0, 0, 0, 0, 1, 0};
    int n = c.size();
    int jumps = 0;
    // Starts trying to jump in cloud 1
    int i = 1;
    while (i<n) {
        if (c[i+1] == 0) {
            i++;
            jumps++;
        } else if (c[i] == 0) {
            jumps++;
        }
        i++;
    }
    cout << jumps << endl;
    return jumps;
}