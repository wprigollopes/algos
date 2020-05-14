#include <iostream>
#include <vector>

using namespace std;

bool isOutOfOrder(int i, int num, vector<int> array) {
    if (i == 0) {
        return num > array[i+1];
    }
    if (i == array.size()-1) {
        return num < array[num-1];
    }
    return num > array[i+1] || num < array[num-1];
}

vector<int> subarraySort(vector<int> array) {
    if (array.size() <= 1) {
        return {-1,-1};
    }
  // Write your code here.
  int minOutOfOrder = 1e8;
  int maxOutOfOrder = -1e8;
  for (int i=0; i<array.size(); i++) {
      int num = array[i];
      if (isOutOfOrder(i, num , array)) {
          minOutOfOrder = min(minOutOfOrder, num);
          maxOutOfOrder = max(maxOutOfOrder, num);
      }
  }

  if (minOutOfOrder == 1e8 && maxOutOfOrder == -1e8) {
      return {-1,-1};
  }
  int subArrayLeftIdx = 0;
  while (minOutOfOrder >= array[subArrayLeftIdx]) {
      subArrayLeftIdx++;
  }
  int subArrayRightIdx = array.size()-1;
  while (maxOutOfOrder <= array[subArrayRightIdx]) {
      subArrayRightIdx--;
  }  
  return {subArrayLeftIdx, subArrayRightIdx};
}

int main() {
    vector<int> array = {1,2,4,7,10,11,7,12,7,7,16,18,19};
    vector<int> result = subarraySort(array);
    return 0;
}