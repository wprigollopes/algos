#include<iostream>
#include<string>

using namespace std;

int main() {
    string s = "ababa";
    int sizeSearch = 9;
    int times = sizeSearch/s.size();
    int remaining = sizeSearch%s.size();
    int response = 0;
    
    for (int i=0; i<s.size(); i++) {
        if (s[i] == 'a') {
            response++;
        }
    }
    response*=times;
    if (remaining>0) {
        string remain = s.substr(0, remaining);
        for (int i=0; i<remain.size(); i++) {
            if (s[i] == 'a') {
                response++;
            }    
        }
    }
    cout << sizeSearch/times << endl;
    cout << "Total: " << response << endl;
}
