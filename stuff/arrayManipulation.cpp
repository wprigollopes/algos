// https://www.youtube.com/watch?v=hDhf04AJIRs
// Used prefix-sum algorithm

#include<iostream>
#include<vector>

using namespace std;

vector<string> split_string(string);

// Complete the arrayManipulation function below.
int main() {
    int n = 4;
    vector<vector<int>> queries = { {2, 3, 603},
                    {1, 1, 286},
                    {4, 4, 882}
    };
    vector<long> result;
    int m = queries.size();
    result.assign(n+1, 0);
    for (int i=0; i<m; i++) {
        result[queries[i][0]]+= queries[i][2];
        result[queries[i][1]+1]-= queries[i][2];
    }
    long maxValue = INT16_MIN;
    for (int i=1; i<result.size(); i++) {
        result[i]+=result[i-1];
        if (maxValue<result[i]) maxValue = result[i];
    }
    return maxValue;
}