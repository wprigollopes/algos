#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    stack<char> stack;
    int i=0;
    if (s.length()>0) {
        while (s[i]) {
            if ((s[i] == '{') || (s[i] == '[') || (s[i] == '(')) {
                stack.push(s[i]);
            }
            if (s[i] == '}') {
                if ((stack.empty()) || (stack.top() != '{')) {
                    return "NO";
                }
                stack.pop();
            }
            if ((s[i] == ']')) {
                if ((stack.empty()) || (stack.top() != '[')) {
                    return "NO";
                }
                stack.pop();
            }
            if ((s[i] == ')')) {
                if ((stack.empty()) || (stack.top() != '(')) {
                    return "NO";
                }
                stack.pop();
            }
            i++;
        }
    }
    return stack.empty() ? "YES" : "NO";   
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
