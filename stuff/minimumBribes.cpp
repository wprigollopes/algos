#include<iostream>
#include<vector>

using namespace std;

int main() {
    vector<int> q = {1, 2, 5, 3, 7, 8, 6, 4};
   int ans = 0;
    for (int i = q.size() - 1; i >= 0; i--) {
        if (q[i] - (i + 1) > 2) {
            cout << "Too chaotic" << endl;
            return 1;
        }
        for (int j = max(0, q[i] - 2); j < i; j++)
            if (q[j] > q[i]) ans++;
    }
    cout << ans << endl; 
    return 0;
}
