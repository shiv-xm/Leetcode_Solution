class Solution {
public:
    string reverseVowels(string s) {
      auto isVowel = [](char c) {
      char lower = tolower(c);
      return lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u';
   };
        
        int left = 0, right = s.length() - 1;

        while (left < right) {
          while (left < right && !isVowel(s[left])) {
                left++;
            }
           while (left < right && !isVowel(s[right])) {
                right--;
            }
              if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};
