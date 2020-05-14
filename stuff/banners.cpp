#include<iostream>
#include<climits>
#include<vector>

using namespace std;

int solution(vector<int> &H) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> fromLeft(H.size(), INT_MIN);
    vector<int> fromRight(H.size(), INT_MIN);
    fromLeft[0] = H[0];
    for (unsigned int i=1; i<H.size(); i++) {
        fromLeft[i] = max(fromLeft[i-1], H[i]);
    }
    fromRight[H.size()-1] = H[H.size()-1];
    for (unsigned int i=H.size()-2; i>=0 && i<H.size(); i--) {
        fromRight[i] = max(fromRight[i+1], H[i]);
    }
    int minAcc = 0;
    for (unsigned int i=0; i<H.size(); i++) {
        minAcc+= min(fromLeft[i], fromRight[i]);
    }
    return minAcc;
}

int main() {
    vector<int> x = {3, 1, 4};
    solution(x);
    return 1;
}