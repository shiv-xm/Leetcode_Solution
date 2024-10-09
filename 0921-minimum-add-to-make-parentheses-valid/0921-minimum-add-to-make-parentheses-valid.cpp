class Solution {
public:
    int minAddToMakeValid(string s) {
    int open_needed = 0;  
    int close_needed = 0; 

    for (char c : s) {
        if (c == '(') {
            close_needed++;  // We need a ')' to balance this '('
        } else { // c == ')'
            if (close_needed > 0) {
                close_needed--;  // This ')' balances an earlier '('
            } else {
                open_needed++;  // We need a '(' to balance this ')'
            }
        }
    }

    // The result is the sum of unbalanced '(' and ')'
    return open_needed + close_needed;
   
    }
};