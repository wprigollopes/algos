#include <vector>
#include <unordered_map>
using namespace std;

// Create a trieNode class
class TrieNode {
	public:
		// Get a map for chars
		unordered_map<char, TrieNode*> children;
		// set the word
		string word;
};

class Trie {
	public:
		TrieNode* root;
		char endSymbol;
	
	Trie() {
		this->root = new TrieNode();
		this->endSymbol = '*';
	}
	
	void insert(string str) {
		TrieNode* curr = this->root;
		for (char s: str) {
			if (curr->children.find(s) == curr->children.end()) {
				TrieNode *newNode = new TrieNode();
				curr->children.insert({s, newNode});
			}
			curr = curr->children[s];
		}
		curr->children.insert({this->endSymbol, NULL});
		curr->word = str;
	}
};

void findSmallStringsIn(string bigString, int startIdx, Trie *trie, unordered_map<string, bool> *containedStrings) {
	// Do here the search
	TrieNode *curr = trie->root;
	for (int i=startIdx; i<bigString.length(); i++) {
		char currentChar = bigString[i];
		if (curr->children.find(currentChar) == curr->children.end()) {
			break;
		}
		curr = curr->children[currentChar];
		if (curr->children.find(trie->endSymbol) != curr->children.end()) {
			containedStrings->insert({curr->word, true});
		}
	}
}


vector<bool> multiStringSearch(string bigString, vector<string> smallStrings) {
  Trie *root = new Trie();
	// Add to trie a structure to use on
	// search for all small strings on a unique trie
	for (int i=0; i<smallStrings.size(); i++) {
		root->insert(smallStrings[i]);
	}
	// For every word, get a map with boolean position
	unordered_map<string, bool> containedStrings;
	// Traverse the string to compare with trie of the smaller strings
	for (int i=0; i<bigString.size(); i++) {
		// This function will check about the strings;
		findSmallStringsIn(bigString, i, root, &containedStrings);
	}
	// And update the result on checkStrings
	vector<bool> stringsCheck;
	//for (auto stringCheck)
  return stringsCheck;
}

int main() {
    multiStringSearch("this is a big string", {"this", "yo", "is", "a", "bigger", "string", "kappa"});
}