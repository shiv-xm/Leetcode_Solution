class Solution {
public:
    int maxDepth(string s) {
        int cnt=0;
        int maxLen=0;
        for(char ch:s){
            if(ch =='('){
               cnt++;
               maxLen =max(cnt,maxLen);
            }else if (ch == ')') {
                cnt--;
            } 
        }
        return maxLen;
    }
};