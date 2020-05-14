#include <vector>
#include <math.h>
#include <bits/stdc++.h> 

using namespace std;

void shiftAndUpdate(vector<int> *threeLargest, int el, int shift) {
	for (int i=0; i<=shift; i++) {
		if (i == shift) {
			threeLargest->at(i) = el;
		} else {
			threeLargest->at(i) = threeLargest->at(i+1);
		}
	}
}

void updateLargest(vector<int> *threeLargest, int el) {
	if (el>threeLargest->at(2)) {
		shiftAndUpdate(threeLargest, el, 2);
	}
	if (el>threeLargest->at(1)) {
		shiftAndUpdate(threeLargest, el, 1);
	}
	if (el>threeLargest->at(0)) {
		shiftAndUpdate(threeLargest, el, 0);
	}
}
int main() {
    vector<int> array = {9, 32, 5, 13, 55, 8, -13};
	vector<int> threeLargest = {INT_MIN, INT_MIN, INT_MIN};
	for (int el: array) {
		updateLargest(&threeLargest, el);
	}
  return 0;
}
