#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// 
// Counting sort used by positive numbers
// By the restriction of numbers is between 0 and 200
// Space O(n) | Time O(nk)
//

int getMiddlePoint(vector<int> range) {
    bool odd = range.size()%2;
    int middle = range.size()/2;
    int counter = 0;
    for (int i=0; i<range.size(); i++) {
        counter+=range[i];
        if (counter == middle) {

        } else if (counter>middle) {
            
        }
    }

}

// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
    // Create the range vector
    vector<int> range(201, 0);
    // Here, we put the values from range on counting sort
    for (int i=0; i<d; i++) {
        range[expenditure[i]]++;
    }

    bool odd = d%2 == 1;
    int middle = d/2;
    
    for (int i=d; i<expenditure.size()-1; i++) {
        // Now, get the median value(s)
        int median, count = 0;
        for (median=0; median<d && count<middle; median++) {
            count+=range[median];
        }
        if (!odd) {

        }
        cout << "Teste" << endl;
        range[expenditure[i-d]]--;
        range[expenditure[i]]++;
    }
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
