#include<iostream>
#include<vector>

using namespace std;


string caesarCypherEncryptor(string str, int key) {
	vector<int> newString;
	int newKey = key % 26;
	for (int i=0; i<str.size(); i++) {
		newString.push_back((str[i]+key)>=122 ? (str[i]+key) : 96 + (str[i]+key) % 122);
	}
  return string(newString.begin(), newString.end());
}


int main() {
    cout << caesarCypherEncryptor("abc", 2) << endl;
    string str = "abc";
    int key = 2;
    vector<int> newString, newString2;
    for (int i=0; i<str.size(); i++) {
		newString.push_back((str[i]+key)>=122 ? (str[i]+key) : 96 + (str[i]+key) % 122);
        newString2.push_back(str[i]+key);
	}
    cout << "TESTE" << endl;
   // cout << string((str[0]+1).begin(), (str[0]+1).end()) << endl;
}


