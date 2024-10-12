class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
    vector<int> start, end;
    for (const auto& interval : intervals) {
        start.push_back(interval[0]);
        end.push_back(interval[1]);
    }
    
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    
    int i = 0, j = 0, groups = 0, maxGroups = 0;
    while (i < start.size()) {
        if (start[i] <= end[j]) {
            groups++; 
            maxGroups = max(maxGroups, groups);  
            i++;
        } else {
            groups--; 
            j++;
        }
    }
    
    return maxGroups;  
    }
};