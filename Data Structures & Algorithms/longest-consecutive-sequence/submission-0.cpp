class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        // Put all elements into the set
        for (int num : nums) {
            st.insert(num);
        }

        int longest = 0;

        // Check every unique number
        for (int num : st) {

            // If num-1 doesn't exist, num is the START of a sequence
            if (st.find(num - 1) == st.end()) {

                int current = num;
                int length = 1;

                // Keep finding the next number
                while (st.find(current + 1) != st.end()) {
                    current++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};