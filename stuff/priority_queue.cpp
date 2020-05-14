#include<iostream>
#include<queue>

using namespace std;
// Eu tenho uma lista de elemntos
// Eu quero a mediana desses elementos, de forma acumulada;
// 3, 4, 5, 6, 8, 12
// n = 3600  O(n) 
// for i =0; i<n; i++
//    for j=0; j<n; j++
//    minHeap / maxHeap
// min 3 4 5 O(n³) = O(n log n)
// max 6 7 8 12
int main() {
    priority_queue<int, vector<int>, less<int>> minHeap; // From minimum to maximum
    priority_queue<int, vector<int>, greater<int>> maxHeap; // From max to min
    
    vector<int> a = {6,12,4,5,3,8,7};
    vector<double> medians;
    // First element = median
    medians.push_back(a[0]);
    medians.push_back((a[0]+a[1])/2);

    if (a.size()>=2) {
        if (a[0]>a[1]) {
            minHeap.push(a[1]);
            maxHeap.push(a[0]);
        } else {
            minHeap.push(a[0]);
            maxHeap.push(a[1]);
        }
    }
    int min = minHeap.top();
    int max = maxHeap.top();

    for (int i=2; i<a.size(); i++) {
        if (a[i]<=min) {
            minHeap.push(a[i]);
        } else if (a[i]>=max) {
            maxHeap.push(a[i]);
        } else {
            if (a[i]-min>max-a[i]) {
                maxHeap.push(a[i]);
            } else {
                minHeap.push(a[i]);
            }
        }
        // Balance heaps
        int minSize = minHeap.size();
        int maxSize = maxHeap.size();
        if (abs(minSize-maxSize)>=2) {
            if (minSize>maxSize) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            } else {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }

        min = minHeap.top();
        max = maxHeap.top();
        
        // If even get min and max heap
        if ((i+1)%2==0) {
            // Get min and max heap
            double value = (double)(min+max)/2;
            value = (value*10)/10;
            medians.push_back(value);
        } else {
            // Get from the major heap
            
            if (minSize>maxSize) {
                medians.push_back(min);
            } else {
                medians.push_back(max);
            }
        }
    }
    return 0;
}