string twoStrings(string s1, string s2) {
    unordered_map<char, char> letters1;
    for (char l1: s1) {
        letters1[l1] = l1;
    }
    for (auto l2: s2) {
        if (letters1[l2]) {
            return "YES";
        }
    }
    return "NO";
}