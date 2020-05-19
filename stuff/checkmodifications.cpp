#include <bits/stdc++.h>

using namespace std;

string isValid(string s) {
    unordered_map<char, long> counts;
    unordered_map<int, long> frequency;

    for (int i=0; i<s.size(); i++) {
        counts[s[i]]++;
    }
    for (auto count: counts) {
        frequency[count.second]++;
    }
    if (frequency.size()>2) {
        return "NO";
    }
    vector<int> diff;
    for (auto f: frequency) {
        if (f.second == 1) {
            frequency.erase(f.first);
            return "YES";
        }
        diff.push_back(f.second);
    }
    if (abs(diff[0]-diff[1])>1) {
        return "NO";
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
