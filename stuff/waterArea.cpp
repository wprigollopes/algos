#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

int waterArea(vector<int> heights) {
    int n = heights.size()-1;
	vector<int> left(n, 0);
	int lastSize = 0;
	for (int i=0; i<=n; i++) {
		left[i] = lastSize;
		lastSize = max(lastSize, heights[i]);
	}
	lastSize = 0;
	vector<int>right(n, 0);
	for (int i=n; i>=0; i--) {
		right[i] = lastSize;
		lastSize = max(lastSize, heights[i]);
	}
	for (int i=0; i<=n; i++) {
        int w = 0;
        int minHeight = min(left[i], right[i]);
        if (heights[i] < minHeight) {
            w = minHeight - heights[i];
        } else {
            w = 0;
        }
        heights[i] = w;
    }
    return accumulate(heights.begin(), heights.end(), 0);
};

int main() {
    vector<int> teste = {0,8,0,0,5,0,0,10,0,0,1,1,0,3};
    int result = waterArea(teste);
    cout << result << endl;
    return 0;
}