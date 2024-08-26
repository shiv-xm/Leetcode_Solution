class Solution {
public:
    int countSeniors(vector<string>& details) {
        int seniorCount = 0; // Initialize a count of seniors

        // Iterate over each string in the details vector
        for (const auto& detail : details) {
            // Extract the age from the string. Assuming that the age
            // starts at the 12th character (index 11) and is 2 digits long.
            int age = stoi(detail.substr(11, 2));

            // Increment the senior count if the age is greater than 60
            seniorCount += (age > 60) ? 1 : 0;
        }
        // Return the total count of seniors
        return seniorCount;
    }
};