class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res;
        res.push_back(first);  

        for (int i = 0; i < encoded.size(); i++) {
            int next = encoded[i] ^ res.back();  // res[i] = encoded[i] ^ res[i-1]
            res.push_back(next);
        }

        return res;
    }
};
