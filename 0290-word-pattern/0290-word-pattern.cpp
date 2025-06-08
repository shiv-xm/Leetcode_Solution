class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;
        istringstream iss(s);

        // Split s into words
        while (iss >> word) {
            words.push_back(word);
        }

        // Length mismatch means pattern cannot match
        if (pattern.length() != words.size()) {
            return false;
        }

        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern[i];
            string w = words[i];

            // If c is already mapped to a different word, return false
            if (charToWord.count(c)) {
                if (charToWord[c] != w)
                    return false;
            } else {
                charToWord[c] = w;
            }

            // If w is already mapped to a different char, return false
            if (wordToChar.count(w)) {
                if (wordToChar[w] != c)
                    return false;
            } else {
                wordToChar[w] = c;
            }
        }

        return true;
    }
};