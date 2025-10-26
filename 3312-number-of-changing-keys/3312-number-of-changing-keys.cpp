class Solution {
public:
    int countKeyChanges(string s) {
        if(s.empty()) return 0;
        int cnt = 0;
        string str = s; 
        for(char &c : str) c = tolower(c);

        for(int i = 1; i < str.size(); i++) { 
            if(str[i] != str[i-1]) cnt++;
        }
        return cnt;
    }
};
